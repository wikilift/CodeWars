//https://www.codewars.com/kata/54cb771c9b30e8b5250011d4/train/dart


import java.math.BigInteger;

public class Faberge {
    public static BigInteger height(BigInteger n, BigInteger m) {
        if (n.equals(BigInteger.ZERO) || m.equals(BigInteger.ZERO)) return BigInteger.ZERO;

        BigInteger result = BigInteger.ZERO;
        BigInteger comb = BigInteger.ONE;

        BigInteger i = BigInteger.ONE;
        while (i.compareTo(n.min(m)) <= 0) {
            comb = comb.multiply(m.subtract(i).add(BigInteger.ONE)).divide(i);
            result = result.add(comb);
            i = i.add(BigInteger.ONE);
        }

        return result;
    }
}
