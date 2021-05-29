#!/usr/bin/env python

import unittest
import fak


class MeinTest(unittest.TestCase):
    def testBerechnung(self):
        self.assertEqual(fak.fak(5), 120)
        self.assertEqual(fak.fak(10), 3628800)
        self.assertEqual(fak.fak(20), 2432902008176640000)
        
    def testAusnahmen(self):
        self.assertRaises(ValueError, fak.fak, -1)


if __name__ == "__main__":
    unittest.main()
