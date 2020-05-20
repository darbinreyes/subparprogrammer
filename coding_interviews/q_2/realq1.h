struct BoundedArray;

typedef struct BoundedArray boundedStringArray;

struct BoundedArray
{
  int size;
  char** arr;
};

boundedStringArray* popularNToys(int numToys, int topToys,
                                    boundedStringArray* toys,
                                    int numQuotes,
                                    boundedStringArray* quotes);