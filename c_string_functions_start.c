//Author: Bob Langelaan
//Date:   Feb 12, 2023

// This exercise will give you an opportunity to try your hand at creating
// functions that manipulate null terminated character arrays.

// NOTE 1 - I have provided main() test program. All you have to do is to 
//          implement the functions. You should study main() to ensure you
//          understand the code that tests your functions. Make sure 
//          especially that you are comfortable with the function calls.


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Required for isalpha(), isdigit() and tolower() functions
#include <conio.h> // Required for _getch() function

// prototypes of functions you are to implement below
int find_first(const char s[], char c); //function 1
int replace_last(char s[], char oldChar, char newChar); //function 2
int count_occ(const char s[], char c); //function 3
int count_alpha(const char s[]); //function 4
int is_all_digits(const char s[]); //function 5
void lowercase_copy(char dest[], const char src[]); //function 6
int is_valid_bcit_id(const char id[]); //function 7
void return_first_word(const char[], char[]);  // Function 8
void return_second_word(const char[], char[]);  // Function 9
int return_count_of_words(const char[]);  // Function 10
void return_nth_word(const char[], char[], int);  // Function 11

void StringFunction()
{
	int test = 1;
	char buffer[100]; // used in 3 of the 4 last functions

	// Test data defined below
	const char* sl1 = "How are you today?";

	char sa1[] = "How are you today?";

	const char* sl2 = "0123456789";
	const char* sl3 = "01234a56789";

	const char* sl4 = "AbCd123EfGh()*&%$#@";
	char sa2[30];

	const char* sl5 = "a00198877"; // Valid id
	const char* sl6 = "A12345678"; // Valid id
	const char* sl7 = "x00198877"; // Invalid id - no 'a' or 'A' as first char
	const char* sl8 = "A1234567";  // Invalid id - too few digits
	const char* sl9 = "A123456789";// Invalid id - too many digits
	const char* sl10 = "A1234x678";// Invalid id - not all chars are digits after 'A'

	const char* sl11 = "Count the number of words";
	const char* sl12 = "  Count the number  of words again  ";
	const char* sl13 = "  One  ";
	const char* sl14 = "";

	// Test function 1
	printf("Test Function %d\n", test++);
	int index = find_first(sl1, 'a');
	printf("%s%s%s%d\n", "The index of the first 'a' in the string: \"", sl1, "\" is: ", index);

	index = find_first(sl1, 'z');
	printf("%s%s%s%d\n", "The index of the first 'z' in the string: \"", sl1, "\" is: ", index);

	// Test function 2
	printf("\nTest Function %d\n", test++);
	printf("%s%s%s", "The index of the last 'a' replaced by 'z' in the string: \"", sa1, "\" is: ");
	index = replace_last(sa1, 'a', 'z');
	printf("%d\n", index);
	printf("%s%s%c", "After replacing 'a' with 'z', the string becomes: \"", sa1, '\"');

	printf("\n%s%s%s", "The index of the last 'a' replaced by 'z' in the string: \"", sa1, "\" is: ");
	index = replace_last(sa1, 'a', 'z');
	printf("%d\n", index);
	printf("%s%s%c", "After replacing 'a' with 'z', the string becomes: \"", sa1, '\"');

	printf("\n%s%s%s", "The index of the last 'a' replaced by 'z' in the string: \"", sa1, "\" is: ");
	index = replace_last(sa1, 'a', 'z');
	printf("%d\n", index);

	// Test function 3
	printf("\nTest Function %d\n", test++);
	int count = count_occ(sl1, 'a');
	printf("%s%s%s%d\n", "The number of 'a's in the string: \"", sl1, "\" is: ", count);
	count = count_occ(sl1, 'z');
	printf("%s%s%s%d\n", "The number of 'z's in the string: \"", sl1, "\" is: ", count);

	// Test function 4
	printf("\nTest Function %d\n", test++);
	count = count_alpha(sl4);
	printf("%s%s%s%d\n", "The number of alpha chars in the string: \"", sl4, "\" is: ", count);

	// Test function 5
	printf("\nTest Function %d\n", test++);
	printf("%s%s%s%s\n", "The string: \"", sl2, "\" is: ", (is_all_digits(sl2) ? "all digits" : "not all digits"));
	printf("%s%s%s%s\n", "The string: \"", sl3, "\" is: ", (is_all_digits(sl3) ? "all digits" : "not all digits"));

	// Test function 6
	printf("\nTest Function %d\n", test++);
	printf("%s%s%s", "The string: \"", sl4, "\" converted to lower case is: \"");
	lowercase_copy(sa2, sl4);
	printf("%s%c\n", sa2, '\"');

	// Test function 7
	printf("\nTest Function %d\n", test++);
	printf("%s%s%s%s\n", "The string: \"", sl5, "\" is ", (is_valid_bcit_id(sl5) ? "a valid id." : "an invalid id."));
	printf("%s%s%s%s\n", "The string: \"", sl6, "\" is ", (is_valid_bcit_id(sl6) ? "a valid id." : "an invalid id."));
	printf("%s%s%s%s\n", "The string: \"", sl7, "\" is ", (is_valid_bcit_id(sl7) ? "a valid id." : "an invalid id."));
	printf("%s%s%s%s\n", "The string: \"", sl8, "\" is ", (is_valid_bcit_id(sl8) ? "a valid id." : "an invalid id."));
	printf("%s%s%s%s\n", "The string: \"", sl9, "\" is ", (is_valid_bcit_id(sl9) ? "a valid id." : "an invalid id."));
	printf("%s%s%s%s\n", "The string: \"", sl10, "\" is ", (is_valid_bcit_id(sl10) ? "a valid id." : "an invalid id."));

	// Test function 8
	printf("\nTest Function %d\n", test++);
	return_first_word(sl11, buffer);
	printf("%s%s%s%s\n", "The first word in the string: \"", sl11, "\" is: ", buffer);
	return_first_word(sl12, buffer);
	printf("%s%s%s%s\n", "The first word in the string: \"", sl12, "\" is: ", buffer);
	return_first_word(sl13, buffer);
	printf("%s%s%s%s\n", "The first word in the string: \"", sl13, "\" is: ", buffer);
	return_first_word(sl14, buffer);
	printf("%s%s%s%s\n", "The first word in the string: \"", sl14, "\" is: ", buffer);

	// Test function 9
	printf("\nTest Function %d\n", test++);
	return_second_word(sl11, buffer);
	printf("%s%s%s%s\n", "The second word in the string: \"", sl11, "\" is: ", buffer);
	return_second_word(sl12, buffer);
	printf("%s%s%s%s\n", "The second word in the string: \"", sl12, "\" is: ", buffer);
	return_second_word(sl13, buffer);
	printf("%s%s%s%s\n", "The second word in the string: \"", sl13, "\" is: ", buffer);
	return_second_word(sl14, buffer);
	printf("%s%s%s%s\n", "The second word in the string: \"", sl14, "\" is: ", buffer);

	// Test function 10
	printf("\nTest Function %d\n", test++);
	printf("%s%s%s%d\n", "The number of words in the string: \"", sl11, "\" is: ", return_count_of_words(sl11));
	printf("%s%s%s%d\n", "The number of words in the string: \"", sl12, "\" is: ", return_count_of_words(sl12));
	printf("%s%s%s%d\n", "The number of words in the string: \"", sl13, "\" is: ", return_count_of_words(sl13));
	printf("%s%s%s%d\n", "The number of words in the string: \"", sl14, "\" is: ", return_count_of_words(sl14));

	// Test function 11
	printf("\nTest Function %d\n", test++);
	return_nth_word(sl11, buffer, 4);
	printf("%s%s%s%s\n", "The 4th word in the string: \"", sl11, "\" is: ", buffer);
	return_nth_word(sl12, buffer, 6);
	printf("%s%s%s%s\n", "The 6th word in the string: \"", sl12, "\" is: ", buffer);
	return_nth_word(sl13, buffer, 4);
	printf("%s%s%s%s\n", "The 4th word in the string: \"", sl13, "\" is: ", buffer);
	return_nth_word(sl14, buffer, 4);
	printf("%s%s%s%s\n", "The 4th word in the string: \"", sl14, "\" is: ", buffer);

	puts("");

}

// Return index of first occurrence of char c in char array s.
// Return -1 if contents of c is not found.
int find_first(const char s[], char c)
{
	int value = -1;
	int i = 0;

	while (s[i] != '\0') {
		if (s[i] == c) {
			value = i;
		}
		i++;
	}

	return value;
}

// Replace last occurence of oldChar with newChar in s.
// Return index of character replaced and -1 if no character replaced
int replace_last(char s[], char oldChar, char newChar)
{
	int value = -1;
	int i = 0;
	int sameChar = 0;
	int repeatedChar = 0;

	while (s[i] != '\0') {
		if (s[i] == oldChar) {
			sameChar++;
		}
		i++;
	}

	i = 0;

	while (s[i] != '\0') {
		if (s[i] == oldChar) {
			repeatedChar++;
		}
		if (repeatedChar == sameChar && s[i] == oldChar) {
			s[i] = newChar;
			value = i;
		}
		i++;
	}

	return value;
}

// Return the number of occurrences of c in s.
int count_occ(const char s[], char c)
{
	int i = 0;
	int count = 0;

	while (s[i] != '\0') {
		if (s[i] == c) {
			count++;
		}
		i++;
	}

	return count;
}

// Return the number of alpha characters in s.
// HINT - use the C library function isalpha() as part of your solution.
int count_alpha(const char s[])
{
	int i = 0;
	int count = 0;

	while (s[i] != '\0') {
		if (isalpha(s[i])) {
			count++;
		}
		i++;
	}

	return count;

}

// Return true if all the characters in s are digits and false otherwise.
// HINT - use the C library function isdigit() as part of your solution.
int is_all_digits(const char s[])
{
	int i = 0;
	int allDigits = 1;

	while (s[i] != '\0') {
		if (!isdigit(s[i])) {
			allDigits = 0;
		}
		i++;
	}

	return allDigits;
}

// Copy contents of src to dest, and in the process of doing so,
//      replace all upper case characters to lower case characters.
// HINT - use the C library function tolower() as part of your solution.
//      - tolower() returns char unchanged if it is not an upper case character
void lowercase_copy(char dest[], const char src[])
{
	dest[0] = '\0'; // Why null? Because we are going to append to it
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = tolower(src[i]);
		i++;
	}
	dest[i] = '\0';
}

// Check to see if the string id is a valid BCIT id.  Assume it is valid
//    if the first character is either a 'a' or a 'A' and is followed by
//    exactly 8 digits.
// HINT - use the C library function isdigit() as part of your solution.
int is_valid_bcit_id(const char id[])
{
	int valid = 1;
	int i = 1;

	if (toupper(id[0]) != 'A') {
		valid = 0;
	}
	else {
		while (id[i] != '\0' && i <= 9) {
			if (!isdigit(id[i])) {
				valid = 0;
			}
			i++;
		}
	}
	if (i != 9) {
		valid = 0;
	}
	printf("%d\n", i);
	return valid;
}



// NOTE THAT THE REMAINING FUNCTIONS ARE MORE CHALLENGING



// Return in the output string the first word found in the input string.
// You may assume if isspace() returns true (1) for a character, it is NOT part of a word.
// Return an empty string if there is no first word.
// 
// Try to code this function so that the input string is traversed only once at most.
//
// HINT - use the C library function isspace() as part of your solution.
//      - You may not use any other library functions.
void return_first_word(const char input[], char output[])
{
	// find first character of first word
	while ((*input != '\0') && (isspace(*input)))
	{
		++input;
	}

	// copy first word to output
	while ((*input != '\0') && (!isspace(*input)))
	{
		*output++ = *input++;
	}

	// add NULL to end of output string
	*output = '\0';
}

// Return in the output string the second word found in the input string.
// You may assume if isspace() returns true (1) for a character, it is NOT part of a word.
// Return an empty string if there is no second word.
//
// Try to code this function so that the input string is traversed only once at most.
// 
// HINT - use the C library function isspace() as part of your solution.
//      - You may not use any other library functions.
void return_second_word(const char input[], char output[])
{
	// find first character of first word
	while ((*input != '\0') && (isspace(*input)))
	{
		++input;
	}

	// skip past first word
	while ((*input != '\0') && (!isspace(*input)))
	{
		++input;
	}

	// find first character of second word
	while ((*input != '\0') && (isspace(*input)))
	{
		++input;
	}

	// copy second word to output
	while ((*input != '\0') && (!isspace(*input)))
	{
		*output++ = *input++;
	}

	// add NULL to end of output string
	*output = '\0';
}

// Return the number of words found in the input string.
// You may assume if isspace() returns true (1) for a character, it is NOT part of a word.
//
// HINT - use the C library function isspace() as part of your solution.
//      - You may not use any other library functions.
int return_count_of_words(const char input[])
{
	int count = 0;

	// find first character of first word
	while ((*input != '\0') && (isspace(*input)))
	{
		++input;
	}

	// Perform this loop until end of input
	while (*input != '\0')
	{
		++count;

		// skip past word
		while ((*input != '\0') && (!isspace(*input)))
		{
			++input;
		}

		// find first character of next word
		while ((*input != '\0') && (isspace(*input)))
		{
			++input;
		}

	}

	return count;
}

// Return in the output string the nth word found in the input string.
// You may assume if isspace() returns true (1) for a character, it is NOT part of a word.
// Return an empty string if there is no nth word.
//
// Try to code this function so that the input string is traversed only once at most.
//
// HINT - use the C library function isspace() as part of your solution.
//      - You may not use any other library functions.
void return_nth_word(const char input[], char output[], int n)
{
	// find first character of first word
	while ((*input != '\0') && (isspace(*input)))
	{
		++input;
	}

	// skip past n-1 words
	int count = 1;
	while ((*input != '\0') && (count < n))
	{
		// skip past word "count"
		while ((*input != '\0') && (!isspace(*input)))
		{
			++input;
		}

		// find first character of next word
		while ((*input != '\0') && (isspace(*input)))
		{
			++input;
		}

		++count;
	}


	// copy nth word to output
	while ((*input != '\0') && (!isspace(*input)))
	{
		*output++ = *input++;
	}

	// add NULL to end of output string
	*output = '\0';
}
