#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

float t;

struct NewsPaperData {
  int paperid;
  float price[7];
  float weaklyPrice = 0;
};

void calculateBudget(struct NewsPaperData toi, struct NewsPaperData hindu,
                     struct NewsPaperData et, struct NewsPaperData bm,
                     struct NewsPaperData ht) {
  for (int i = 0; i < 7; i++) {
    toi.weaklyPrice += toi.price[i];
  }
  for (int i = 0; i < 7; i++) {
    hindu.weaklyPrice += hindu.price[i];
  }
  for (int i = 0; i < 7; i++) {
    et.weaklyPrice += et.price[i];
  }
  for (int i = 0; i < 7; i++) {
    bm.weaklyPrice += bm.price[i];
  }
  for (int i = 0; i < 7; i++) {
    ht.weaklyPrice += ht.price[i];
  }

  float arr[5];

  arr[0] = toi.weaklyPrice;
  arr[1] = hindu.weaklyPrice;
  arr[2] = et.weaklyPrice;
  arr[3] = bm.weaklyPrice;
  arr[4] = ht.weaklyPrice;

  int n = sizeof(arr) / sizeof(int);
  sort(arr, arr + n);

  float m = 0;
  int maxnum = 0;
      vector<std::string> elements;

  for (int i = 0; i < n; i++) {
    float currSum = 0;
    int num = 0;
    for (int j = i; j < n; j++) {
      currSum += arr[j];
      num++;
      if (currSum > m && currSum <= t && num >= maxnum) {
        m = currSum;
        maxnum = num;
        switch (j) {
        case 0:
          elements.push_back("toi");
        case 1:
          elements.push_back("hindu");
        case 2:
          elements.push_back("et");
        case 3:
          elements.push_back("bm");
        case 4:
          elements.push_back("ht");
        }
      }
    }
  }
  cout<<"{";
  for(int i=elements.size();i>=elements.size()-maxnum;i--){
    cout<<elements[i]<<" ";
  }
  cout<<"}"<<endl;
  cout << m;

  // cout << toi.weaklyPrice << endl
  //      << hindu.weaklyPrice << endl
  //      << et.weaklyPrice << endl
  //      << bm.weaklyPrice << endl
  //      << ht.weaklyPrice;
}

int main() {

  struct NewsPaperData toi = {1, {3, 3, 3, 3, 3, 5, 6}};
  struct NewsPaperData hindu = {2, {2.5, 2.5, 2.5, 2.5, 2.5, 4, 4}};
  struct NewsPaperData et = {3, {4, 4, 4, 4, 4, 4, 10}};
  struct NewsPaperData bm = {4, {1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5}};
  struct NewsPaperData ht = {5, {2, 2, 2, 2, 2, 4, 4}};

  cout << "Weekly Budget: ";
  cin >> t;

  calculateBudget(toi, hindu, et, bm, ht);
}
