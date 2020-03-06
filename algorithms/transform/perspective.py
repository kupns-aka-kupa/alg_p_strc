import cv2
import numpy as np


def order_points(pts):
    rect = np.zeros((4, 2), dtype="float32")
    s = pts.sum(axis=1)
    rect[0] = pts[np.argmin(s)]
    rect[2] = pts[np.argmax(s)]
    diff = np.diff(pts, axis=1)
    rect[1] = pts[np.argmin(diff)]
    rect[3] = pts[np.argmax(diff)]
    return rect


def perspective_detect(img):
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    ret, threshold_image = cv2.threshold(gray, 150, 255, 0)
    contours, hierarchy = cv2.findContours(threshold_image, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    cv2.drawContours(img, contours, -1, (0, 255, 0), 3)
    edges = cv2.Canny(threshold_image, 100, 200, apertureSize=3)
    blurred = cv2.GaussianBlur(threshold_image, (51, 51), 0)
    cv2.imshow("", blurred)
    xy = intersections(blurred)
    return np.array([[265, 180], [1045, 180], [60, 1335], [1160, 1365]], dtype="float32")


def intersections(edged):
    h, w = edged.shape
    hl = cv2.HoughLines(edged, 2, np.pi / 180, 400)
    n = hl.shape[0]
    T = np.zeros((n, 2), dtype=np.float32)
    R = np.zeros(n, dtype=np.float32)

    for i in range(n):
        T[i:i + 1, 0] = np.cos(hl[i][:, 1])
        T[i:i + 1, 1] = np.sin(hl[i][:, 1])
        R[i] = hl[i][:, 0]
        # for rho, theta in hl[i]:
        #     a = np.cos(theta)
        #     b = np.sin(theta)
        #     x0 = a * rho
        #     y0 = b * rho
        #     x1 = int(x0 + 1000 * (-b))
        #     y1 = int(y0 + 1000 * a)
        #     x2 = int(x0 - 1000 * (-b))
        #     y2 = int(y0 - 1000 * a)
        #     cv2.line(img, (x1, y1), (x2, y2), (0, 0, 255), 2)
    c = n * (n - 1) // 2
    XY = np.zeros((c, 2))
    for i in range(n):
        for j in range(i + 1, n):
            XY[i + j - 1, :] = np.linalg.inv(T[[i, j], :]).dot(R[[i, j]])
    XY[(XY[:, 0] > 0) & (XY[:, 0] <= w) & (XY[:, 1] > 0) & (XY[:, 1] <= h)]
    return XY


def transform(image, node_points):
    rect = order_points(node_points)
    tl, tr, br, bl = rect
    w1 = np.sqrt(((br[0] - bl[0]) ** 2) + ((br[1] - bl[1]) ** 2))
    w2 = np.sqrt(((tr[0] - tl[0]) ** 2) + ((tr[1] - tl[1]) ** 2))
    h1 = np.sqrt(((tr[0] - br[0]) ** 2) + ((tr[1] - br[1]) ** 2))
    h2 = np.sqrt(((tl[0] - bl[0]) ** 2) + ((tl[1] - bl[1]) ** 2))
    width = max(int(w1), int(w2))
    height = max(int(h1), int(h2))
    out_size = (width, height)
    dst = np.array([[0, 0], [width, 0], [width, height], [0, height]], dtype="float32")
    m = cv2.getPerspectiveTransform(rect, dst)
    return cv2.warpPerspective(image, m, out_size)


def main(f: str, o: str = None):
    if o is None:
        o = "transformed" + f
    img = cv2.imread(f)
    pts = perspective_detect(img)
    warped = transform(img, pts)
    cv2.imwrite(o, img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
