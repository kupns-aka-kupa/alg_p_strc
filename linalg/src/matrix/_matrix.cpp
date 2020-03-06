#include "_matrix.h"

Matrix::Matrix() : array(nullptr) {}

Matrix::Matrix(uint32_t m, uint32_t n) : m(m), n(n)
{
    this->array = new double *[this->m];
    for(uint32_t i = 0; i < this->m; i++)
    {
        array[i] = new double[n];
        for(uint32_t j = 0; j < this->n; j++)
        {
            array[i][j] = 0;
        }
    }
}

Matrix::Matrix(uint32_t m, uint32_t n, double **array)
    :m(m), n(n), array(array) {}

Matrix::Matrix(const Matrix &m)
{
    this->m = m.m;
    this->n = m.n;
    this->array = new double *[this->m];
    for(uint32_t i = 0; i < this->m; i++)
    {
        array[i] = new double[n];
        for(uint32_t j = 0; j < this->n; j++)
        {
            array[i][j] = m.array[i][j];
        }
    }
}

Matrix::~Matrix() { _minor_dealloc(array , n); }

std::string Matrix::to_str()
{
    std::ostringstream strs;
    strs << std::endl;
    for(uint32_t i = 0; i < m; i++)
    {
        strs  << "| ";
        for(uint32_t j = 0; j < n; j++)
        {
            strs << array[i][j] << " ";
        }
        strs << " |" << std::endl;
    }
    return strs.str();
}

void Matrix::print() { std::cout << to_str(); }

uint32_t *Matrix::get_size() { return new uint32_t[2]{m, n}; }

double ** Matrix::get_array() { return array; }

Matrix & Matrix::operator = (const Matrix &mr)
{
    if (this == & mr) {
        return *this;
    }
    *this = Matrix(mr);
    return *this;
}

const Matrix &operator + (const Matrix &m) { return m; }

Matrix operator - (const Matrix &m)
{
    for(uint32_t i = 0; i < m.m; i++)
    {
        for(uint32_t j = 0; j < m.n; j++)
        {
            m.array[i][j] = -m.array[i][j];
        }
    }
    return Matrix(m);
}

const Matrix &operator ++ (Matrix &m)
{
    if (!(m.n == m.m)) { return m; }

    for(uint32_t i = 0; i < m.m; i++)
    {
        m.array[i][i] += 1;
    }
    return m;
}

const Matrix operator ++ (Matrix &m, int)
{
    if (!(m.n == m.m)) { return m; }

    Matrix tmp = m;
    for(uint32_t i = 0; i < m.m; i++)
    {
        m.array[i][i] += 1;
    }
    return tmp;
}

const Matrix & operator -- (Matrix &m)
{
    if (!(m.n == m.m)) { return m; }

    for(uint32_t i = 0; i < m.m; i++)
    {
        m.array[i][i] -= 1;
    }
    return m;
}

const Matrix operator -- (Matrix &m, int)
{
    if (!(m.n == m.m)) { return m; }

    Matrix tmp = m;
    for(uint32_t i = 0; i < m.m; i++)
    {
        m.array[i][i] -= 1;
    }
    return tmp;
}

const Matrix operator + (const Matrix &ml, const Matrix &mr)
{
    if (!(ml.n == mr.n && ml.m == mr.m))
    {
        return Matrix();
    }
    Matrix m = ml;

    for(uint32_t i = 0; i < m.m; i++)
    {
        for(uint32_t j = 0; j < m.n; j++)
        {
            m.array[i][j] = ml.array[i][j] + mr.array[i][j];
        }
    }
    return m;
}

Matrix &operator += (Matrix &ml, const Matrix &mr)
{
    if (!(ml.n == mr.n && ml.m == mr.m))
    {
        return ml;
    }
    for(uint32_t i = 0; i < ml.m; i++)
    {
        for(uint32_t j = 0; j < ml.n; j++)
        {
            ml.array[i][j] += mr.array[i][j];
        }
    }
    return ml;
}

const Matrix operator - (const Matrix &ml, const Matrix &mr)
{
    if (!(ml.n == mr.n && ml.m == mr.m))
    {
        return Matrix();
    }

    Matrix m(ml);
    for(uint32_t i = 0; i < m.m; i++)
    {
        for(uint32_t j = 0; j < m.n; j++)
        {
            m.array[i][j] = ml.array[i][j] - mr.array[i][j];
        }
    }
    return m;
}

Matrix &operator -= (Matrix &ml, const Matrix &mr)
{
    if (!(ml.n == mr.n && ml.m == mr.m))
    {
        return ml;
    }
    for(uint32_t i = 0; i < ml.m; i++)
    {
        for(uint32_t j = 0; j < ml.n; j++)
        {
            ml.array[i][j] -= mr.array[i][j];
        }
    }
    return ml;
}

bool operator == (const Matrix &ml, const Matrix &mr)
{
    if (!(ml.n == mr.n && ml.m == mr.m))
    {
        return false;
    }
    for(uint32_t i = 0; i < ml.m; i++)
    {
        for(uint32_t j = 0; j < ml.n; j++)
        {
            if(ml.array[i][j] != mr.array[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool operator != (const Matrix &ml, const Matrix &mr)
{
    return !(ml == mr);
}

const Matrix operator * (Matrix &m, const double k)
{
    Matrix mo(m);
    for(uint32_t i = 0; i < mo.m; i++)
    {
        mo._row_mul(i, k);
    }
    return mo;
}

const Matrix operator * (const double k, Matrix &m) { return m * k; }

Matrix &operator *= (Matrix &m, const double k)
{
    for(uint32_t i = 0; i < m.m; i++)
    {
        m._row_mul(i, k);
    }
    return m;
}

const Matrix operator * (const Matrix &ml, const Matrix &mr)
{
    if (ml.n != mr.m)
    {
        return Matrix();
    }
    Matrix m(ml.m, mr.n);

    for(uint32_t i = 0; i < m.m; i++)
    {
        for(uint32_t j = 0; j < m.n; j++)
        {
            double el = 0;
            for(uint32_t k = 0; k < ml.n; k++)
            {
                 el += ml.array[i][k] * mr.array[k][j];
            }
            m.array[i][j] = el;
        }
    }
    return m;
}

Matrix &operator *= (Matrix &ml, const Matrix &mr)
{
    if (ml.n != mr.m) { return ml; }
    ml.n =  mr.n;
    double ** array = new double * [ml.m];
    for(uint32_t i = 0; i < ml.m; i++)
    {
        array[i] = new double[ml.n];
        for(uint32_t j = 0; j < ml.n; j++)
        {
            double el = 0;
            for(uint32_t k = 0; k < ml.n; k++)
            {
                 el += ml.array[i][k] * mr.array[k][j];
            }
            array[i][j] = el;
        }
    }
    Matrix::_minor_dealloc(ml.array, ml.m);
    ml.array = array;
    return ml;
}

const Matrix operator / (Matrix &m, const double k) { return (m * (1 / k)); }

Matrix & operator /= (Matrix &m, const double k) { return (m *= (1 / k)); }

Matrix & operator <<= (Matrix &m, const double *rowin)
{
//    double **tmp = m.array;
//    m.array = new double *[m.m + 1];
//    for(uint32_t i = 0; i < m.m; i++)
//    {
//        m.array[i] = new double[m.n];
//        for(uint32_t j = 0; j < m.n; j++)
//        {
//            m.array[i][j] = tmp[i][j];
//        }
//    }
//    Matrix::_minor_dealloc(tmp, m.m);
//    m.m++;

//    m.array[m.m] = new double[m.n];
//    for(uint32_t j = 0; j < m.n; j++)
//    {
//        m.array[m.m][j] = rowin[j];
//    }
    return m;
}

const Matrix operator << (const Matrix &m, const double *rowin)
{
    Matrix tmp(m);
    tmp <<= rowin;
    return tmp;
}

Matrix &operator >>= (Matrix &m, double *rowout)
{
    double *tmp = new double [m.n];
    for(uint32_t j = 0; j < m.n; j++)
    {
        tmp[j] = m.array[m.m][j];
    }
    rowout = tmp;
    delete m.array[m.m];
    m.m--;
    return m;
}

const Matrix operator >> (const Matrix &m, double *rowout)
{
    Matrix tmp(m);
    tmp >>= rowout;
    return tmp;
}

void Matrix::push_row(const double *const rowin, const uint32_t n, ...)
{

}

double *Matrix::pop_row(const double n, ...)
{

}

void Matrix::push_col(const double *const colin, const uint32_t n, ...)
{

}

double *Matrix::pop_col(const double n, ...)
{

}

void Matrix::_row_swap(uint32_t i, uint32_t k)
{
    if (i > m || k > m) return;
    double *temp = array[i];
    array[i] = array[k];
    array[k] = temp;
}

void Matrix::_row_sum(uint32_t i, uint32_t k)
{
    if (i > m || k > m) return;
    for (uint32_t j = 0; j < n; j++)
    {
        array[i][j] += array[k][j];
    }
}

void Matrix::_row_mul(uint32_t i, double k)
{
    for (uint32_t j = 0; j < n; j++)
    {
        array[i][j] *= k;
    }
}

void Matrix::_minor_dealloc(double ** m, uint32_t n)
{
    for (uint32_t i = 0; i < n; i++)
    {
        delete [] m[i];
    }
    delete [] m;
}


double **Matrix::_minor_alloc(double **m, uint32_t i, uint32_t n)
{
    uint32_t keys[n][n];
    for (uint32_t j = 0; j < n; j++)
    {
        for (uint32_t p = 0; p < n; p++)
        {
            keys[j][p] = (i + p + 1) % (n + 1);
        }
        uint32_t size = sizeof(keys) / sizeof(keys[0]);
        std::sort(keys[j], keys[j] + size);
    }
    double **minor = new double *[n];
    for (uint32_t j = 1; j < n + 1; j++)
    {
        minor[j - 1] = new double [n];
        for (uint32_t p = 1; p < n + 1; p++)
        {
            minor[j - 1][p - 1] = m[j][keys[j - 1][p - 1]];
        }
    }
    return minor;
}

void Matrix::transpose()
{
    uint32_t k = n;
    n = m;
    m = k;

    double **result = new double *[m];

    for(uint32_t i = 0; i < m; i++)
    {
        result[i] = new double [n];
        for(uint32_t j = 0; j < n; j++)
        {
            result[i][j] = array[j][i];
        }
    }
    _minor_dealloc(array , n);
    array = result;
}
