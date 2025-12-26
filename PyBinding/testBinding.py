import bindingModule

mat = bindingModule.Matrix(3, 3)
mat.insertValue(0, 0, 10)
print("Matrix:")
mat.print()
temp = mat.getValue(0, 0)


