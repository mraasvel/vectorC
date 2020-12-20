**help**

	If you have any advice on how this can be implemented better/more effectively feel free to let me know

**C++ Vectors**

	Makefile compiles all .c files into a static library.

**What is it?**

	A vector is a dynamic array which you can easily use without worrying about how much size you have to allocate beforehand.
	A certain initial_size will be allocated, if it's insufficient more memory will be allocated so that there will always be enough space.
	If the table was allocated for 2 integers, and you pushback a third integer, the table will be reallocated with twice it's previous size.
	Warning: don't change the size and nmemb variables inside of the vector.

**USAGE**

	1. declare vector:
		t_vector *vector;

	2. initialize vector:
		vector = vector_init(<initial_size>, sizeof(data_type));
		Note: for the other vector types the data type is already determined.
		example for string vector:
			vector = vector_init(<initial_size>, sizeof(char*));
		Note: initial_size will be the size malloced for table within the vector.
		If size is set to 0, 2 * sizeof(data_type) will be allocated instead.

	3. push values into t_vector:
		vector_pushback(vector, ft_strdup("abcd")); for strings
		vector_pushback(vector, (void*)'a')); for chars
		vector_pushback(vector, (void*)1234987)); for ints
		
	4. push values into other vector types:
		fltvect_pushback(vector, 1234.56789);

	5. retrieve values:
		((int*)vector->table)[nmemb - 1]; gives last member of int table
		Note: you only have to typecast with the t_vector data type.
		example:
			printf("%f\n", dblvect->table[nmemb - 1]);

	6. Free vector after you are finished using it:
		vector_free(vector, del_function);
		Note: you can specify NULL if whatever is in table doesn't need to be freed.

		If you have a vector of strings you would free it like: vector_free(vector, free);
		If you have a vector of some other type, you should create your own del_function to send with this function.

		Other data types don't require a del_function:
			int32vect_free(vector);

