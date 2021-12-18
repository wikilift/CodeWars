using System.Collections;
using System.Linq;

namespace codewars.OwnKatas
{
    public class Locust
    {
        public static long howManyFishes(int[] numbers, int daysLoop)
        {
         
            var zeros = numbers.ToList().Where(x => x == 0).Count();
            var ones = numbers.ToList().Where(x => x == 1).Count();
            var twos = numbers.ToList().Where(x => x == 2).Count();
            var threes = numbers.ToList().Where(x => x == 3).Count();
            var fours = numbers.ToList().Where(x => x == 4).Count();
            var fives = numbers.ToList().Where(x => x == 5).Count();
            var sixs = numbers.ToList().Where(x => x == 6).Count();
            var sevens = numbers.ToList().Where(x => x == 7).Count();
            var eights = numbers.ToList().Where(x => x == 8).Count();

       Dictionary<int, long> dict = new Dictionary<int, long>(){
                                                   {0,zeros},
                                                   {1,ones},
                                                   {2,twos},
                                                   {3,threes},
                                                   {4,fours},
                                                   {5,fives},
                                                   {6,sixs},
                                                   {7,sevens},
                                                   {8,eights}};
                                                        
            bool generate = false;
      
            long temporal = 0;

          for (int i = 0; i < daysLoop; i++)
            {
                Console.WriteLine($"\t Dia {i + 1}");
                if (dict[0] > 0)
                {
                    temporal = dict[0];
                    generate = true;
                    dict[0] = 0;
                }
                else
                {
                    generate = false;
                }

                if (dict[1] > 0)
                {
                    dict[0] = dict[1];
                    dict[1] = 0;
                }
                if (dict[2] > 0)
                {
                    dict[1] = dict[2];
                    dict[2] = 0;
                }
                if (dict[3] > 0)
                {
                    dict[2] = dict[3];
                    dict[3] = 0;
                }
                if (dict[4] > 0)
                {
                    dict[3] = dict[4];
                    dict[4] = 0;
                }
                if (dict[5] > 0)
                {
                    dict[4] = dict[5];
                    dict[5] = 0;
                }

                if (dict[6] > 0)
                {

                    dict[5] = dict[6];
                    dict[6] = 0;


                }
                if (generate)
                {
                    dict[6] = temporal;
                }

                if (dict[7] > 0)
                {
                    dict[6] += dict[7];
                    dict[7] = 0;


                }

                if (dict[8] > 0)
                {
                    dict[7] = dict[8];

                    dict[8] = 0;

                }
                if (generate)
                    dict[8] += temporal;
            }

            long result = 0;
            foreach (var item in dict)
            {
                result+=item.Value;
            }
            
            return result;







        }


    }
}

      




