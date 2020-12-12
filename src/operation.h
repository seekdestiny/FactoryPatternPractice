#ifndef Operation_H
#define Operation_H

#include "image.h"
#include <memory>
#include <map>

using namespace std;

class Operation {
  public:
    virtual void execute(Image& image) = 0;
    virtual ~Operation(){};
};

typedef shared_ptr<Operation> (*CreateOperation)(const string&);

class ResizeOperation : public Operation
{
  public:
    ResizeOperation(const string& params);
    virtual void execute(Image& image) override;
    virtual ~ResizeOperation(){};
    static shared_ptr<Operation> Create(const string& params){return make_shared<ResizeOperation>(params);};

  private:
    int param;
};

class ConvertOperation: public Operation
{
  public:
    ConvertOperation(const string& params);
    virtual void execute(Image& image) override;
    virtual ~ConvertOperation(){};
    static shared_ptr<Operation> Create(const string& params){return make_shared<ConvertOperation>(params);};

  private:
    int param1;
    int param2;
};

class OperationFactory {
  private:
    typedef std::map<string, CreateOperation> OperationMap;
    OperationMap _operation_map;

  public:
    OperationFactory();
    OperationFactory(const OperationFactory&);
    OperationFactory& operator=(const OperationFactory&);

    shared_ptr<Operation> getOperation(const string& operation);

    ~OperationFactory() {_operation_map.clear();};

    static OperationFactory& getInstance() {
      static OperationFactory instance;
      return instance;
    }

    void Register(const string& operation_name, CreateOperation opCreate);
};

#endif // Operation_H
