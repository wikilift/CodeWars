//https://www.codewars.com/kata/54cb771c9b30e8b5250011d4/train/dart

import java.math.BigInteger

fun height(n: BigInteger, m: BigInteger): BigInteger {
    if (n == BigInteger.ZERO || m == BigInteger.ZERO) return BigInteger.ZERO

    var result = BigInteger.ZERO
    var comb = BigInteger.ONE
    var i = BigInteger.ONE

    val min = n.min(m)
    while (i <= min) {
        comb = comb.multiply(m - i + BigInteger.ONE).divide(i)
        result += comb
        i += BigInteger.ONE
    }

    return result
}
