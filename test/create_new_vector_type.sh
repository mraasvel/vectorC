# Idea: VECTOR_TYPE can be like t_struct; then t_ should only be added to data type initializations to prevent t_t_structvect
# 'char*' should be valid input: somehow detect the start and don't add it to VECTOR_NAME(?) to prevent t_char*vect, but replace it with a 'p' or something



# sed 's/VECTOR_TYPE/<datatype var>' syntax for replacement; pipe it to new file or add -i flag to make changes into file directly