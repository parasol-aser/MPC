CC=/usr/bin/clang
CFLAGS=-g
LDFLAGS=-lpthread

LLVM_CC=llvm-gcc
LLVM_LLC=llc
LLVM_OPT=opt
LLVM_LINK=llvm-link
SYMB_PASS=$(INSTALL_PATH)/llvm-2.9/Release+Asserts/lib/SymbiosisBBPass.so

all: plain

KLEE0:
	$(LLVM_CC) -emit-llvm -c -g M0.c -o M0.bc
	$(LLVM_OPT) -load $(SYMB_PASS) -symbiosisBB M0.bc -o M0_inst.bc

KLEE1:
	$(LLVM_CC) -emit-llvm -c -g M1.c -o M1.bc
	$(LLVM_OPT) -load $(SYMB_PASS) -symbiosisBB M1.bc -o M1_inst.bc

KLEE3:
	$(LLVM_CC) -emit-llvm -c -g M3.c -o M3.bc
	$(LLVM_OPT) -load $(SYMB_PASS) -symbiosisBB M3.bc -o M3_inst.bc

KLEE5:
	$(LLVM_CC) -emit-llvm -c -g M5.c -o M5.bc
	$(LLVM_OPT) -load $(SYMB_PASS) -symbiosisBB M5.bc -o M5_inst.bc

KLEE7:
	$(LLVM_CC) -emit-llvm -c -g M7.c -o M7.bc
	$(LLVM_OPT) -load $(SYMB_PASS) -symbiosisBB M7.bc -o M7_inst.bc

KLEE9:
	$(LLVM_CC) -emit-llvm -c -g M9.c -o M9.bc
	$(LLVM_OPT) -load $(SYMB_PASS) -symbiosisBB M9.bc -o M9_inst.bc

test:
	$(LLVM_CC) -emit-llvm -c -g test.c -o test.bc
	$(LLVM_OPT) -load $(SYMB_PASS) -symbiosisBB test.bc -o test_inst.bc

clean:
	-rm *.o *.s *.ll *.bc klee-out-* CheckedPath* index_* result* paralleled *.bc -rf
