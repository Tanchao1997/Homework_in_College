using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace 订单管理
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void dgvOrder_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            this.oleDbDataAdapter1.Fill(this.dataSet11);
        }

        private void dgvOrderDetail_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            this.oleDbDataAdapter1.Fill(this.dataSet11);
        }
        
        private void Form1_Load(object sender, EventArgs e)
        {
            this.oleDbDataAdapter1.Fill(this.dataSet11);
            this.oleDbDataAdapter2.Fill(this.dataSet21);
        }

        private void btnSelect_Click(object sender, EventArgs e)
        {
            //从订单表中中获取当前行的SalesOrderID
            string SalesOrderID = dgvOrder.Rows[this.dgvOrder.CurrentRow.Index].Cells[0].Value.ToString(); 
            //修改查询命令
            string whereStmt = "SalesOrderID=" + SalesOrderID;
            String oldSelectStmt = oleDbDataAdapter2.SelectCommand.CommandText;
                                
            String selectStmt = oleDbDataAdapter2.SelectCommand.CommandText;
            if (whereStmt.Length > 0) selectStmt += " WHERE " + whereStmt;
                       
            oleDbDataAdapter2.SelectCommand.CommandText=selectStmt;
            //将订单明细表对应的数据集清空
            dataSet21.Clear();
            //使用新的查询命令填充数据集
            oleDbDataAdapter2.Fill(dataSet21);
            //把查询命令恢复
            oleDbDataAdapter2.SelectCommand.CommandText = oldSelectStmt; 
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            int index = -1;
            foreach (DataRow dataRow in dataSet21.SalesOrderDetail.Rows)
            {
                DataRowState rowState = dataRow.RowState;      
                //如果该行已被删除，跳出
                if (rowState == DataRowState.Deleted)
                    continue;                                 
                //否则，添加索引，执行删除操作
                index++;                                
                if (this.dgvOrderDetail.CurrentRow.Index == index)
                {
                    dataRow.Delete();
                    break;
                }
            } 
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            try
            {
                this.oleDbDataAdapter2.Update(this.dataSet21.SalesOrderDetail);
                MessageBox.Show("更新成功!");    
            }
            catch (Exception ex)
            {
                MessageBox.Show("更新失败!\n" + ex.Message);
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {   //检查所有行rowguid列是否为空                          
                foreach (DataRow dataRow in this.dataSet21.SalesOrderDetail.Rows)
                {                                      
                    if (dataRow.RowState == DataRowState.Added)
                    {                                            
                        if (dataRow["rowguid"].Equals(System.DBNull.Value))
                        {
                            dataRow["rowguid"] = Guid.NewGuid();
                        }
                    }
                }
                this.oleDbDataAdapter2.Update(this.dataSet21.SalesOrderDetail);
                MessageBox.Show(" 保存成功!");
            }
        catch (Exception ex)            
            {
                MessageBox.Show("ᨳ保存失败!\n" + ex.Message);            
            }
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            if (dataSet21.HasChanges())         //判断有无未保存的修改                 
            {             
                //弹出是否确认退出对话框
                MessageBoxButtons warn = MessageBoxButtons.OKCancel;
                DialogResult res = MessageBox.Show("有未保存的修改，"+"是否确定退出","警告哦",warn);
                if (res == DialogResult.OK)
                {                                        
                    Application.Exit();
                }
                else
                {
                    return;
                }
            }            //若无未保存修改直接退出
            else 
            {
             Application.Exit();
            }
        }
    }
}
