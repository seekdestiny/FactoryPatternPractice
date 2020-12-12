#ifndef Image_H
#define Image_H
#include <vector>

using namespace std;

class Image {
  public:
    Image(int height=1, int weight=1) : h(height), w(weight) {
       pixels = vector<vector<int>>(h, vector<int>(w, 0));
    };

    ~Image() {};

  private:
    vector<vector<int>> pixels;
    int h;
    int w;
};

#endif // Image_H
