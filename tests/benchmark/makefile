test: setup
	../../TestCompile -r ../../lib -r . --use-ssa --make Benchmark 2>&1 | grep -v module | ooef

setup:
	rm -rf obj exe sym
	mkdir obj sym

clean:
	rm -f obj/* sym/* exe/* 

distclean: 
	rm -rf obj sym exe
