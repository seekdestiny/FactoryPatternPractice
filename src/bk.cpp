#include "operation.h"
#include <iostream>
#include <sstream>

using namespace std;

void ResizeOperation::execute(Image& image, const string& params) {
  int param = 0;
  stringstream p1(params);
  p1 >> param;
    
  cout << "resize img " << param << " \n";
}

void ConvertOperation::execute(Image& image, const string& params) {
  int param1, param2 = 0;
  string op_rand1 = params.substr(0, params.find(" "));
  string op_rand2 = params.substr(params.find(" ") + 1);
  stringstream p1(op_rand1);
  stringstream p2(op_rand2);

  p1 >> param1;
  p2 >> param2;
    
  cout << "convert img " << param1 << " " << param2 << " \n";
}

OperationFactory::OperationFactory() {
  _operation_map["convert"] = make_shared<ConvertOperation>();
  _operation_map["resize"] = make_shared<ResizeOperation>();
}

shared_ptr<Operation> OperationFactory::getOperation(const string& operation_name) {
  if (_operation_map.find(operation_name) != _operation_map.end()) {
    return _operation_map[operation_name];
  }
  cout << "Invalid operation!\n"; 
  return NULL;
}
