if(EXISTS "D:/Arquivos/Comp/CES-12/lab_1hash2/build/lab1tests[1]_tests.cmake")
  include("D:/Arquivos/Comp/CES-12/lab_1hash2/build/lab1tests[1]_tests.cmake")
else()
  add_test(lab1tests_NOT_BUILT lab1tests_NOT_BUILT)
endif()
