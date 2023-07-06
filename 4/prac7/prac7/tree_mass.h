#ifndef _TREE_AND_MASS_
#define _TREE_AND_MASS_
#define ALPHABET  "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

typedef char* KeyType;
typedef char* ValueType;


typedef struct _Tree {

	KeyType key;
	ValueType value;
	struct _Tree* left;
	struct _Tree* right;

} Tree;

typedef struct _Node
{
	KeyType key;
	ValueType value;
}Mass;


void InsertTree(Tree** tree, KeyType key, ValueType value);
char* SearchValueByKey(Tree** tree, KeyType key);
Tree* DeleteTreeValueByKey(Tree* tree, KeyType key);
void DeleteTree(Tree* tree);
void outputTree(Tree* tree);


Mass** InitMass(Mass** buffer, size_t elements);
ValueType GetValueFromMass(Mass** mass, KeyType key);
Mass** DeleteMassElement(Mass** buffer, KeyType key);
void FreeMass(Mass** mass);
Mass** ApendMass(Mass** buffer, KeyType key, ValueType value, size_t kolvo);
void outputMass(Mass** m);

#endif // !_TREE_AND_MASS_