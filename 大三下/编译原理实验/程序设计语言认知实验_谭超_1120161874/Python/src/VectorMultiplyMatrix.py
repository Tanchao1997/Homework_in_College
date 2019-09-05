# -*- coding: utf-8 -*-
"""
Created on Sat Mar  2 14:45:12 2019

@author: tc
"""
import time
class Matrix:
    
    def __init__(self,row,column):
        self.row=row
        self.column=column
        self.matrix=[[0 for j in range(self.column)]for i in range(self.row)]
    def inputMatrixFromFile(self,fileName):
        with open(str(fileName),'r') as f:
            line =f.readline().strip()
            linestr=line.split(' ')
            #print(linestr)
            self.row=int(linestr[0])
            self.column=int(linestr[1])
            self.matrix=[[0 for j in range(self.column)]for i in range(self.row)]
            for i in range(0,self.row):
                line=f.readline().strip()
                linestr=line.split(' ')
                #print('linestr:',linestr)
                for j in range(0,self.column):
                    self.matrix[i][j]=int(linestr[j])
                    #print('int(linestr):',int(linestr[j]))
                    #print('matrix:',self.matrix[i][j])
                #print()
    def printMatrixToFile(self,fileName):
        with open(str(fileName),'w') as f:
            f.write(str(self.row))
            f.write(' ')
            f.write(str(self.column))
            f.write('\n')
            for i in range(0,self.row):
                for j in range(0,self.column):
                    f.write(str(self.matrix[i][j]))
                    f.write(' ')
                f.write('\n')
        
    def matrixMultiply(self,otherMatrix):
        result=Matrix(self.row,otherMatrix.column)
        for i in range(0,self.row):
            for j in range(0,otherMatrix.column):
                for k in range(0,self.column):
                    result.matrix[i][j]+=self.matrix[i][k]*otherMatrix.matrix[k][j]
        return result
                    
if __name__=='__main__':
    vector=Matrix(0,0)
    vector.inputMatrixFromFile('vector.txt')
    matrix=Matrix(0,0)
    matrix.inputMatrixFromFile('matrix.txt')
    startTime=time.time();
    result=vector.matrixMultiply(matrix)
    endTime=time.time();
    result.printMatrixToFile('result.txt')
    print('running time:',endTime-startTime,'ms')
    