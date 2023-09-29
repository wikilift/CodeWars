namespace codewars.Katas
{
    public class movingZeros
    {
        // https://www.codewars.com/kata/52597aa56021e91c93000cb0/train/csharp

        public static int[] MoveZeroes(int[] arr)
        {
           var t=arr.Where(n=> n!=0).ToList();
           foreach(var x in Enumerable.Range(0,arr.Where(t=> t ==0).Count())){
               t.Add(0);
           }
           return t.ToArray();
        }
    }
}