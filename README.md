## Pseudo-Random
- [x] Middle square

#### Note:
```diff
-! some bugs in range [0, 1]
-! sometimes out of bounds
-! im lazy to fix it now )
```

## Sorting
- [x] Bubles sort
- [x] Insertion sort
- [x] Change sort
- [x] Merge sort

## Searcing
- [x] Linear search
- [x] Binary search

## Prime numbers

- [x] Sieve of Eratosthenes
- [x] Atkin Sieve

#### Note:
<details>
    <summary>First 10*16+8 primes</summary>
    <table border="1"><tr><td><p>2</p></td><td><p>3</p></td><td><p>5</p></td><td><p>7</p></td><td><p>11</p></td><td><p>13</p></td><td><p>17</p></td><td><p>19</p></td><td><p>23</p></td><td><p>29</p></td></tr><tr><td><p>31</p></td><td><p>37</p></td><td><p>41</p></td><td><p>43</p></td><td><p>47</p></td><td><p>53</p></td><td><p>59</p></td><td><p>61</p></td><td><p>67</p></td><td><p>71</p></td></tr><tr><td><p>73</p></td><td><p>79</p></td><td><p>83</p></td><td><p>89</p></td><td><p>97</p></td><td><p>101</p></td><td><p>103</p></td><td><p>107</p></td><td><p>109</p></td><td><p>113</p></td></tr><tr><td><p>127</p></td><td><p>131</p></td><td><p>137</p></td><td><p>139</p></td><td><p>149</p></td><td><p>151</p></td><td><p>157</p></td><td><p>163</p></td><td><p>167</p></td><td><p>173</p></td></tr><tr><td><p>179</p></td><td><p>181</p></td><td><p>191</p></td><td><p>193</p></td><td><p>197</p></td><td><p>199</p></td><td><p>211</p></td><td><p>223</p></td><td><p>227</p></td><td><p>229</p></td></tr><tr><td><p>233</p></td><td><p>239</p></td><td><p>241</p></td><td><p>251</p></td><td><p>257</p></td><td><p>263</p></td><td><p>269</p></td><td><p>271</p></td><td><p>277</p></td><td><p>281</p></td></tr><tr><td><p>283</p></td><td><p>293</p></td><td><p>307</p></td><td><p>311</p></td><td><p>313</p></td><td><p>317</p></td><td><p>331</p></td><td><p>337</p></td><td><p>347</p></td><td><p>349</p></td></tr><tr><td><p>353</p></td><td><p>359</p></td><td><p>367</p></td><td><p>373</p></td><td><p>379</p></td><td><p>383</p></td><td><p>389</p></td><td><p>397</p></td><td><p>401</p></td><td><p>409</p></td></tr><tr><td><p>419</p></td><td><p>421</p></td><td><p>431</p></td><td><p>433</p></td><td><p>439</p></td><td><p>443</p></td><td><p>449</p></td><td><p>457</p></td><td><p>461</p></td><td><p>463</p></td></tr><tr><td><p>467</p></td><td><p>479</p></td><td><p>487</p></td><td><p>491</p></td><td><p>499</p></td><td><p>503</p></td><td><p>509</p></td><td><p>521</p></td><td><p>523</p></td><td><p>541</p></td></tr><tr><td><p>547</p></td><td><p>557</p></td><td><p>563</p></td><td><p>569</p></td><td><p>571</p></td><td><p>577</p></td><td><p>587</p></td><td><p>593</p></td><td><p>599</p></td><td><p>601</p></td></tr><tr><td><p>607</p></td><td><p>613</p></td><td><p>617</p></td><td><p>619</p></td><td><p>631</p></td><td><p>641</p></td><td><p>643</p></td><td><p>647</p></td><td><p>653</p></td><td><p>659</p></td></tr><tr><td><p>661</p></td><td><p>673</p></td><td><p>677</p></td><td><p>683</p></td><td><p>691</p></td><td><p>701</p></td><td><p>709</p></td><td><p>719</p></td><td><p>727</p></td><td><p>733</p></td></tr><tr><td><p>739</p></td><td><p>743</p></td><td><p>751</p></td><td><p>757</p></td><td><p>761</p></td><td><p>769</p></td><td><p>773</p></td><td><p>787</p></td><td><p>797</p></td><td><p>809</p></td></tr><tr><td><p>811</p></td><td><p>821</p></td><td><p>823</p></td><td><p>827</p></td><td><p>829</p></td><td><p>839</p></td><td><p>853</p></td><td><p>857</p></td><td><p>859</p></td><td><p>863</p></td></tr><tr><td><p>877</p></td><td><p>881</p></td><td><p>883</p></td><td><p>887</p></td><td><p>907</p></td><td><p>911</p></td><td><p>919</p></td><td><p>929</p></td><td><p>937</p></td><td><p>941</p></td></tr><tr><td><p>947</p></td><td><p>953</p></td><td><p>967</p></td><td><p>971</p></td><td><p>977</p></td><td><p>983</p></td><td><p>991</p></td><td><p>997</p></td></tr></table>
    <details>
        <summary>And massive form</summary>
        [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997]
    </details>
</details>

## Features
- [x] Work time
- [x] HTML table output
