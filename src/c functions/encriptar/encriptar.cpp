#include <node.h>
#include <v8.h>
#include "encriptar.h" // Include the header for your C compiled function

void EncriptarCpp(const v8::FunctionCallbackInfo<v8::Value> &args){
    v8::Isolate *isolate = args.GetIsolate();

    // Check the number of arguments
    if (args.Length() < 3){
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
        return;
    }

    // Extract the string parameter
    v8::String::Utf8Value strParam(isolate, args[0]);
    char *strValue = *strParam;

    int intArg1 = args[1]->Int32Value(isolate->GetCurrentContext()).ToChecked();
    int intArg2 = args[2]->Int32Value(isolate->GetCurrentContext()).ToChecked();

    // Call your C function with the extracted arguments
    int result = encriptar(strValue, intArg1, intArg2);

    // Convert the result to a JavaScript value
    v8::Local<v8::Number> jsResult = v8::Number::New(isolate, result);

    args.GetReturnValue().Set(jsResult);
}

void Init(v8::Local<v8::Object> exports){
    NODE_SET_METHOD(exports, "encriptarCpp", EncriptarCpp);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)
