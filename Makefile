all:
	@cd src; make all

clean:
	@cd src; make clean
	@rm -rf latex html

docs:
	@doxygen doxygen.cfg
	@rm -rf latex
