import argparse
import os

parser = argparse.ArgumentParser()
parser.add_argument('num', type=int)
args = parser.parse_args()

n = args.num
fn = f'../solutions/{n}.cpp'
os.system(f'g++ -o sol {fn}; ./sol')