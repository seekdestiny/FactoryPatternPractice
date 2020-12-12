#ifndef Operation_H
#define Operation_H

#include "image.h"
#include <memory>
#include <map>

using namespace std;

class Operation {
  public:
    virtual void execute(Image& image, const string& params) = 0;
    virtual ~Operation(){};
};

class ResizeOperation : public Operation
{
  public:
    virtual void execute(Image& image, const string& params) override;
    virtual ~ResizeOperation(){};
};

class ConvertOperation: public Operation
{
  public:
    virtual void execute(Image& image, const string& params) override;
    virtual ~ConvertOperation(){};
};

class OperationFactory {
  private:
    typedef std::map<string, shared_ptr<Operation>> OperationMap;
    OperationMap _operation_map;

  public:
    OperationFactory();
    OperationFactory(const OperationFactory&);
    OperationFactory& operator=(const OperationFactory&);

    shared_ptr<Operation> getOperation(const string& operation_name);

    ~OperationFactory() {_operation_map.clear();};

    static OperationFactory& getInstance() {
      static OperationFactory instance;
      return instance;
    }
};

#endif // Operation_H
