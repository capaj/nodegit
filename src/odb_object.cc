/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <v8.h>
#include <node.h>
#include <string.h>

#include "git2.h"

#include "../include/odb_object.h"
#include "../include/wrapper.h"
#include "../include/oid.h"

using namespace v8;
using namespace node;

GitOdbObject::GitOdbObject(git_odb_object *raw) {
  this->raw = raw;
}

GitOdbObject::~GitOdbObject() {
  git_odb_object_free(this->raw);
}

void GitOdbObject::Initialize(Handle<v8::Object> target) {
  HandleScope scope;

  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(String::NewSymbol("OdbObject"));

  NODE_SET_PROTOTYPE_METHOD(tpl, "objectData", ObjectData);
  NODE_SET_PROTOTYPE_METHOD(tpl, "objectSize", ObjectSize);
  NODE_SET_METHOD(tpl, "objectType", ObjectType);
  NODE_SET_PROTOTYPE_METHOD(tpl, "oid", Oid);


  constructor_template = Persistent<Function>::New(tpl->GetFunction());
  target->Set(String::NewSymbol("OdbObject"), constructor_template);
}

Handle<Value> GitOdbObject::New(const Arguments& args) {
  HandleScope scope;

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    return ThrowException(Exception::Error(String::New("git_odb_object is required.")));
  }

  GitOdbObject* object = new GitOdbObject((git_odb_object *) External::Unwrap(args[0]));
  object->Wrap(args.This());

  return scope.Close(args.This());
}

Handle<Value> GitOdbObject::New(void *raw) {
  HandleScope scope;
  Handle<Value> argv[1] = { External::New((void *)raw) };
  return scope.Close(GitOdbObject::constructor_template->NewInstance(1, argv));
}

git_odb_object *GitOdbObject::GetValue() {
  return this->raw;
}


Handle<Value> GitOdbObject::ObjectData(const Arguments& args) {
  HandleScope scope;
  

  const void * result = git_odb_object_data(
    ObjectWrap::Unwrap<GitOdbObject>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = Wrapper::New((void *)result);
  return scope.Close(to);
}

Handle<Value> GitOdbObject::ObjectSize(const Arguments& args) {
  HandleScope scope;
  

  size_t result = git_odb_object_size(
    ObjectWrap::Unwrap<GitOdbObject>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = Uint32::New(result);
  return scope.Close(to);
}

Handle<Value> GitOdbObject::ObjectType(const Arguments& args) {
  HandleScope scope;
  

  git_otype result = git_odb_object_type(
    ObjectWrap::Unwrap<GitOdbObject>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = Int32::New(result);
  return scope.Close(to);
}

Handle<Value> GitOdbObject::Oid(const Arguments& args) {
  HandleScope scope;
  

  const git_oid * result = git_odb_object_id(
    ObjectWrap::Unwrap<GitOdbObject>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = GitOid::New((void *)result);
  return scope.Close(to);
}

Persistent<Function> GitOdbObject::constructor_template;
