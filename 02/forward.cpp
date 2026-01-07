// Chapter 2: C++ Basics: Functions and Files
// Date: 2025-01-07
// Forward Declaration
// Compile: clang++ forward.cpp -o forward

/* Recursive Dependencies
 * 
 * Consider the following two structs:
 * 
 * struct emp_t {
 *      char name[32];
 *      unsigned int emp_id;
 *      struct occ_t occ;
 * };
 * 
 * struct occ_t {
 *      char designation[32];
 *      unsigned int salary;
 *      struct emp_t boss;
 * };
 *
 * So we can see that the two structs depend on each other.
 * The compiler will complain because when processing emp_t, it has not seen occ_t before.
 * We can address this problem by using a forward declaration.
 */

 struct occ_t;

 struct emp_t {
    char name[32];
    unsigned int emp_id;

    /*
     * And here's a subtlety.
     *
     * So now, we have to use a pointer occ_t* instead of occ_t.
     * If we don't use a poninter and do: "struct occ_t occ", the compiler will complain.
     * 
     * This is because the compiler needs to know the SIZE of the struct.
     * While the occ_t has been declared above, the compiler can't determine the size of occ_t.
     * But if we use a pointer, the size of the pointer is known - 8 bytes in a 64-bit system.
     */
    struct occ_t *occ;
 };

struct occ_t {
    char designation[32];
    unsigned int salary;
    struct emp_t boss;
};

int main() {
    return 0;
}