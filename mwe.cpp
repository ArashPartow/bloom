/** Below is a templatized reference implementation. Now, one has to specify
* the type of the `bloom_filter`. Then, only those types can be inserted and queried
* from the Bloom Filter.
*
* In the below example, we first create an bloom_filter<int> and then one of type
* bloom_filter<std::string>. The <int>-type Bloom Filter can be queried for and
* inserted into `size_t` values. There will be an implicit cast taking place but
* it will show the "right" behavior!
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
   bloom_filter<int> filter(parameters);
   filter.insert(-3);
   // Below rightly doesn't compile.
   //  filter.insert(std::string("Foo"));
   //  filter.insert(3.2);
   bloom_filter<std::string> string_filter(parameters);
   string_filter.insert(std::string("foo"));
   // Doesn't compile either.
  //  string_filter.insert(12);

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
           std::cout << "False Negative: " << i << " : size_t" << std::endl;
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
