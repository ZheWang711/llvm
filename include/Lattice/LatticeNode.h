#ifndef LATTICENODE_H_
#define LATTICENODE_H_
/*We should define the LatticeNode to be the abstract class. The LatticeNode can not be instantiated.*/
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;
enum LatticeType{
		/*enumerate all kind of lattice*/
	CPLATTICE,
	CSELATTICE,
	RALATTICE,
	MAYPLATTICE
};
class LatticeNode {
public:
	LatticeNode(LatticeType type): isTop(false), isBottom(false) { this->type = type;}
	LatticeNode(LatticeType type, bool isTop, bool isBottom){ this->type = type; this->isTop = isTop; this->isBottom = isBottom;}
//	LatticeType getType() const{ return type;}
	/*Virtual functions. Cannot use pure virtual functions!!! Otherwise it cannot be initialized in the WorklistAlg class*/
	virtual LatticeNode* join(LatticeNode* node){errs()<< "go to base class join func\n\n\n";return NULL;}
	virtual bool equal(LatticeNode* node){return false;}
	virtual void print(){errs()<<"---LatticeNode Info---\n";}
//Class member variable
	bool isTop;
	bool isBottom;
	LatticeType type; 
};
#endif
