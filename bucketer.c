#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
  //lets assume the rated capacity as 120
  int rated_capacity=120;
  for (int i=0;i<nBatteries;i++)
    {
    //calculate SOH using the formula given 
    float soh =((float)presentCapacities[i]/rated_capacity)*100;
    
    if (soh>80)
    {
      //if soh is above 80 increment healthy
     counts.healthy++;
    }
    else if(soh >= 62 && soh<=80)
    {
      //if soh is above 62 and less than 80 
     counts.exchange++;
    }
    else
    {
      // if soh does not satify the above conditions then increment failed  
    counts.failed++;
    }
    }
  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {113, 116, 80, 95, 92, 70};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
}

int main() {

  testBucketingByHealth();
  return 0;
}
