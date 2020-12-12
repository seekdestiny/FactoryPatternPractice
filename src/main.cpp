#include <iostream>
#include "operation.h"
#include <memory>

using namespace std;

int main() {
  vector<string> operations = {"resize 11", "convert 55 22"};
  vector<Image> images(3);

  int iterImage = 0;
  for (auto& image : images) {
    cout << "Handle " << iterImage << "th image.\n";

    for (auto& operation: operations) {
      shared_ptr<Operation> op = OperationFactory::getInstance().getOperation(operation);
      op->execute(image); 
    }
    iterImage++;
  }

  return 0;
}
