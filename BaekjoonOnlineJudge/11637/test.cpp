#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vote;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);

    vector<int> vote(n + 1);
    int sum = 0;

    for (int i = 1; i <= n; i++) {
      scanf("%d", &vote[i]);
      sum += vote[i];
    }

    int max_person;
    int max_value = *max_element(vote.begin(), vote.end());
    int count = 0;

    for (int i = 1; i <= n; i++) {
      if(vote[i] == max_value) {
        max_person = i;
        count++;
      }
    }
    if (count > 1) printf("no winner\n");
    else if (max_value > sum / 2) printf("majority winner %d\n", max_person);
    else printf("minority winner %d\n", max_person);
  }

  return 0;
}
