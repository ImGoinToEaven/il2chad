#pragma once
#include "Il2Chad/Debug.h"
#include "Il2Chad/Metadata.h"
#include "Il2Chad/Utils.h"
#include "Imports.h"
#include <cstdio>

using namespace Il2Chad::Imports;

void Il2Chad::Debug::dumpObject(Il2CppObject *object) {
  auto klass = Il2Chad::Utils::get_class(object);
  auto klassName = Il2Chad::Utils::get_class_name(klass);

  printf("========== %p : %s ==========\n", object, klassName);

  void *iter = nullptr;
  const FieldInfo *field = nullptr;

  printf("Fields:\n");
  while ((field = il2cpp_class_get_fields(klass, &iter)) != nullptr) {
    const char *fieldName = il2cpp_field_get_name(field);
    auto fieldOffset = il2cpp_field_get_offset(field);
    auto fieldType = il2cpp_field_get_type(field);
    auto fieldTypeName = il2cpp_type_get_name(fieldType);
    printf("\t%s %s: %zx\n", fieldTypeName, fieldName, fieldOffset);

    // todo print values
  }

  // index properties
  iter = nullptr;
  const PropertyInfo *property = nullptr;

  printf("Properties:\n");
  while ((property = il2cpp_class_get_properties(klass, &iter)) != nullptr) {
    const char *propertyName = il2cpp_property_get_name(property);
    auto getter = il2cpp_property_get_get_method(property);
    auto setter = il2cpp_property_get_set_method(property);
    auto type = il2cpp_property_get_type(property);
    auto typeName = il2cpp_type_get_name(type);

    printf("\t%s %s", propertyName, typeName);
    printf("\t\tGetter: %p\n", getter);
    printf("\t\tSetter: %p\n", setter);
    // todo print values
  }

  // index methods
  iter = nullptr;
  const MethodInfo *method = nullptr;

  while ((method = il2cpp_class_get_methods(klass, &iter)) != nullptr) {
    const char *methodName = il2cpp_method_get_name(method);
  }
}