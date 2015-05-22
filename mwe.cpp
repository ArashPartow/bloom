/** The following code shows that when inserting `size_t` into the bloom filter
* and checking for membership using `int`s, there are false-negatives.
*
* That in itself might be understandble because no implicit cast is possible.
* There are, however, two things I would like to see changed:
* 1. The example for false-positive checks from -1 to -100 is clearly misleading!
*    For the example to be meaningful (int) 1 to 100 should be true-positives!
* 2. Document this behaviour. The unsuspecting user should be aware that inserting
*    size_t's and checking with int's doesn't work!
*/
#include <iostream>
#include <string>

#include "bloom_filter.hpp"

int main()
{

   bloom_parameters parameters;

   // How many elements roughly do we expect to insert?
   parameters.projected_element_count = 1000;

   // Maximum tolerable false positive probability? (0,1)
   parameters.false_positive_probability = 0.0001; // 1 in 10000

   // Simple randomizer (optional)
   parameters.random_seed = 0xA5A5A5A5;

   if (!parameters)
   {
      std::cout << "Error - Invalid set of bloom filter parameters!" << std::endl;
      return 1;
   }

   parameters.compute_optimal_parameters();

   //Instantiate Bloom Filter
   bloom_filter filter(parameters);

   // Insert into Bloom Filter
   {
      // Insert some numbers
      for (std::size_t i = 0; i < 100; ++i)
      {
         filter.insert(i);
      }
   }

   // Query Bloom Filter
   {
      // Query the existence of numbers
      for (std::size_t i = 0; i < 100; ++i)
      {
         if (filter.contains(i))
         {
            std::cout << "BF contains: " << i << " : size_t" << std::endl;
         }
         else
         {
           std::cout << "False Negative: " << i << " : int" << std::endl;
         }
      }
      for (int i = 0; i < 100; ++i)
      {
          if (filter.contains(i))
          {
              std::cout << "BF containts: " << i << " : int" << std::endl;
          }
          else
          {
              std::cout << "False Negative: " << i << " : int" << std::endl;
          }
      }

      // Query the existence of invalid numbers
      for (int i = -1; i > -100; --i)
      {
         if (filter.contains(i))
         {
            std::cout << "BF falsely contains: " << i << std::endl;
         }
      }
   }

   return 0;
}
