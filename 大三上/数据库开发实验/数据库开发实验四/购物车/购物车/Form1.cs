using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.OleDb;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace 购物车
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            oleDbDataAdapter1.Fill(dataSet11);
        }
        private void btnLogIn_Click(object sender, EventArgs e)
        {
            if (tbxUserID.Text.Length == 0)
            {
                MessageBox.Show("input your userID!");
            }
            else
            {
                int user_id = Int32.Parse(tbxUserID.Text);
                //修改查询命令
                string whereStmt = " WHERE ShoppingCartID=" + user_id;
                String oldSelectStmt = oleDbDataAdapter2.SelectCommand.CommandText;
                String selectStmt = oleDbDataAdapter2.SelectCommand.CommandText;
                selectStmt += whereStmt;
                oleDbDataAdapter2.SelectCommand.CommandText = selectStmt;
                //通过新的查询命令填充购物车列表对应的数据集
                dataSet21.Clear();
                oleDbDataAdapter2.Fill(dataSet21);
                //将查询命令恢复
                oleDbDataAdapter2.SelectCommand.CommandText = oldSelectStmt;
            }
        }
        private void btnAdd_Click(object sender, EventArgs e)
        {
            //获取用户ID
            int user_id = Int32.Parse(tbxUserID.Text);
            //获取产品ID
            int product_id = (int)dataSet11.Product[dgvProduct.CurrentRow.Index]["ProductID"];
            OleDbCommand command = new OleDbCommand();
            command.Connection = this.oleDbConnection1;
            this.oleDbConnection1.Open();
            OleDbTransaction trans = oleDbConnection1.BeginTransaction();
            //创建一个事务
            try
            {
                command.Transaction = trans;
                string command_text = "EXEC add_to_shoppingcart " + product_id + "," + user_id;
                command.CommandText = command_text;
                command.ExecuteNonQuery();
                trans.Commit();
            }
            catch (Exception ex)
            {
                trans.Rollback();//如果出错则回滚
                MessageBox.Show(ex.ToString());
            }
            finally
            {
                this.oleDbConnection1.Close();
            }
            btnLogIn_Click(sender, e);
        }

        private void btnRemove_Click(object sender, EventArgs e)
        {
            //获取用户ID
            int user_id = Int32.Parse(tbxUserID.Text);
            //获取要移出的产品ID
            int product_id = (int)dataSet11.Product[dgvProduct.CurrentRow.Index]["ProductID"];
            OleDbCommand command = new OleDbCommand();
            command.Connection = this.oleDbConnection1;
            this.oleDbConnection1.Open();
            OleDbTransaction trans = oleDbConnection1.BeginTransaction();
            //构造一个事务
            try
             {
                command.Transaction = trans;
                string command_text = "EXEC remove_from_shoppingcart " + product_id + "," + user_id; command.CommandText = command_text;
                command.ExecuteNonQuery();
                trans.Commit();
            }
            catch (Exception ex)
            {
                trans.Rollback();//如果出错则回滚
                MessageBox.Show(ex.ToString());
            }
            finally
            {
                this.oleDbConnection1.Close();
            }
            btnLogIn_Click(sender, e); 
        }

        

        
    }
}
