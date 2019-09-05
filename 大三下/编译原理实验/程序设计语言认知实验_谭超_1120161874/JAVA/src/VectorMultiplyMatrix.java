package vectorMultiplyMatrix;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStream;

public class VectorMultiplyMatrix {
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		
		Matrix vector=new Matrix();
		vector.inputMatrixFromFile("vector.txt");
		Matrix matrix=new Matrix();
		matrix.inputMatrixFromFile("matrix.txt");
		long startTime=System.currentTimeMillis();
		vector.multiply(matrix,"result.txt");
		long endTime=System.currentTimeMillis();
		System.out.println("running time:"+(endTime-startTime)+"ms");
	}

}

class Matrix{
	int row,column;
	int matrix[][];
	public Matrix(int row,int column) {
		this.row=row;
		this.column=column;
		matrix=new int[row][column];
		for(int i=0;i<row;i++)
			for(int j=0;j<column;j++)
				matrix[i][j]=0;
	}
	public Matrix() {
		this.row=0;
		this.column=0;
	}
	public void inputMatrixFromFile(String fileName) throws IOException {
		BufferedReader in =new BufferedReader(new FileReader(fileName));
		String strLine=in.readLine();
		String[] tem=strLine.split(" ");
		this.row=Integer.parseInt(tem[0]);
		this.column=Integer.parseInt(tem[1]);
		matrix=new int[this.row][this.column];
		for(int i=0;i<row;i++)
			for(int j=0;j<column;j++)
				matrix[i][j]=0;
		for(int i=0;i<this.row;i++) {
			strLine=in.readLine();
			tem=strLine.split(" ");
			for(int j=0;j<this.column;j++)
				this.matrix[i][j]=Integer.parseInt(tem[j]);
		}
		in.close();
	}
	public void outputMatrixToFile(String fileName) throws IOException {
		//OutputStream out= new FileOutputStream(fileName);
		//PrintWriter pw=new PrintWriter(out);
		//BufferedWriter pw =new BufferedWriter(new FileWriter(fileName));
		//OutputStream pw= new FileOutputStream(fileName);
		FileWriter pw=new FileWriter(fileName);
		pw.write(this.row);
		//pw.write(this.row);
		pw.write(' ');
		//pw.write(String.valueOf(this.column));
		pw.write(this.column);
		pw.write('\n');
		for(int i=0;i<this.row;i++) {
			for(int j=0;j<this.column;j++) {
				pw.write(this.matrix[i][j]);
				pw.write(' ');
			}
			pw.write('\n');
		}
		pw.close();
		
	}
	public void multiply(Matrix otherMatrix,String fileName) throws IOException {
		if(this.column!=otherMatrix.row) {
			System.out.println("两矩阵不可相乘\n");
		}
		else {
			Matrix result=new Matrix(this.row,otherMatrix.column);
			for(int i=0;i<this.row;i++)
				for(int j=0;j<otherMatrix.column;j++)
					for(int k=0;k<this.column;k++) 
						result.matrix[i][j]+=this.matrix[i][k]*otherMatrix.matrix[k][j];
			System.out.print("result row:"+result.row+"  result column:"+result.column+"\n");
			for(int i=0;i<result.row;i++) {
				for(int j=0;j<result.column;j++) {
					System.out.println(result.matrix[i][j]);
					//System.out.print(" ");
				}
					
				//System.out.print("\n");
			}
			result.outputMatrixToFile(fileName);
		}
	}
};
