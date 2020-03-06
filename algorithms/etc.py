def xor_reverse(iterable):
    lenght = len(iterable)
    i = 0
    while i < lenght // 2:
        iterable[i] ^= iterable[lenght - i - 1]
        iterable[lenght - i - 1] ^= iterable[i]
        iterable[i] ^= iterable[lenght - i - 1]
        i += 1
    return iterable
