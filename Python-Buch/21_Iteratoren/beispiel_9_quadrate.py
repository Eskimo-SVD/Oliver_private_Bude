#!/usr/bin/env python


class Quadrate:
    def __init__(self, max_n):
        self.MaxN = max_n

    def __getitem__(self, index):
        index += 1 # 0*0 ist nicht sehr interessant...
        if index > len(self) or index < 1:
            raise IndexError
        return index*index

    def __len__(self):
        return self.MaxN


if __name__ == "__main__":
    print(list(Quadrate(20)))

