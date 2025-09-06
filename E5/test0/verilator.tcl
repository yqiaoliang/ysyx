verilator -Wall --cc top.v --exe top_sim.cpp
make -C obj_dir -f Vtop.mk Vtop