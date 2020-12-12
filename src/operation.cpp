#include "operation.h"
#include <iostream>
#include <sstream>

using namespace std;

ResizeOperation::ResizeOperation(const string& params) {
  stringstream p1(params);
  p1 >> param;
}

void ResizeOperation::execute(Image& image) {
  cout << "resize img " << param << " \n";
}

ConvertOperation::ConvertOperation(const string& params) {
  string op_rand1 = params.substr(0, params.find(" "));
  string op_rand2 = params.substr(params.find(" ") + 1);
  stringstream p1(op_rand1);
  stringstream p2(op_rand2);

  p1 >> param1;
  p2 >> param2;
}

void ConvertOperation::execute(Image& image) {
  cout << "convert img " << param1 << " " << param2 << " \n";
}

OperationFactory::OperationFactory() {
  Register("convert", &ConvertOperation::Create);
  Register("resize", &ResizeOperation::Create);
}

shared_ptr<Operation> OperationFactory::getOperation(const string& operation) {
  string operation_name = operation.substr(0, operation.find(" "));
  string operation_rands = operation.substr(operation.find(" ") + 1);

  if (_operation_map.find(operation_name) != _operation_map.end()) {
    return (*_operation_map[operation_name])(operation_rands);
  }
  cout << "Invalid operation!\n"; 
  return NULL;
}

void OperationFactory::Register(const string& operation_name, CreateOperation opCreate)
{
  _operation_map[operation_name] = opCreate;
}
