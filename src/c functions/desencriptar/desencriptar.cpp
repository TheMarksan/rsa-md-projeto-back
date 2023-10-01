#include <node.h>
#include <v8.h>
#include "desencriptar.h" // Include the header for your C compiled function

void DesencriptarCpp(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

  // Check the number of arguments
  if (args.Length() < 4) {
    isolate->ThrowException(v8::Exception::TypeError(
        v8::String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
    return;
  }

  // Extract the int array from the JavaScript arguments
  v8::Local<v8::Array> jsArray = v8::Local<v8::Array>::Cast(args[0]);
  int arrSize = jsArray->Length();
  int* intArray = new int[arrSize];
  for (int i = 0; i < arrSize; i++) {
    v8::Local<v8::Value> jsValue = jsArray->Get(isolate->GetCurrentContext(), i).ToLocalChecked();
    intArray[i] = jsValue->Int32Value(isolate->GetCurrentContext()).ToChecked();
  }

  int intArg1 = args[1]->Int32Value(isolate->GetCurrentContext()).ToChecked();
  int intArg2 = args[2]->Int32Value(isolate->GetCurrentContext()).ToChecked();
  int intArg3 = args[3]->Int32Value(isolate->GetCurrentContext()).ToChecked();

  // Call your C function with the extracted arguments
  int result = desencriptar(intArray, intArg1, intArg2, intArg3, arrSize);

  // Convert the result to a JavaScript value
  v8::Local<v8::Number> jsResult = v8::Number::New(isolate, result);

  // Clean up dynamically allocated memory
  delete[] intArray;

  args.GetReturnValue().Set(jsResult);
}

void Init(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "desencriptarCpp", DesencriptarCpp);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)
