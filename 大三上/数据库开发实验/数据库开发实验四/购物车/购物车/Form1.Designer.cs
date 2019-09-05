namespace 购物车
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.labProduct = new System.Windows.Forms.Label();
            this.labShoppingCar = new System.Windows.Forms.Label();
            this.dgvShoppingCar = new System.Windows.Forms.DataGridView();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnRemove = new System.Windows.Forms.Button();
            this.oleDbSelectCommand1 = new System.Data.OleDb.OleDbCommand();
            this.oleDbUpdateCommand1 = new System.Data.OleDb.OleDbCommand();
            this.oleDbDeleteCommand1 = new System.Data.OleDb.OleDbCommand();
            this.oleDbDataAdapter1 = new System.Data.OleDb.OleDbDataAdapter();
            this.oleDbConnection1 = new System.Data.OleDb.OleDbConnection();
            this.oleDbSelectCommand2 = new System.Data.OleDb.OleDbCommand();
            this.oleDbInsertCommand1 = new System.Data.OleDb.OleDbCommand();
            this.oleDbUpdateCommand2 = new System.Data.OleDb.OleDbCommand();
            this.oleDbDeleteCommand2 = new System.Data.OleDb.OleDbCommand();
            this.oleDbDataAdapter2 = new System.Data.OleDb.OleDbDataAdapter();
            this.dataSet21 = new 购物车.DataSet2();
            this.shoppingCartItemIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.shoppingCartIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.quantityDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.productIDDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dateCreatedDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.modifiedDateDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.labUserID = new System.Windows.Forms.Label();
            this.tbxUserID = new System.Windows.Forms.TextBox();
            this.btnLogIn = new System.Windows.Forms.Button();
            this.dgvProduct = new System.Windows.Forms.DataGridView();
            this.productIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.nameDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colorDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.listPriceDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.weightDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.quantityDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataSet11 = new 购物车.DataSet1();
            ((System.ComponentModel.ISupportInitialize)(this.dgvShoppingCar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet21)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgvProduct)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet11)).BeginInit();
            this.SuspendLayout();
            // 
            // labProduct
            // 
            this.labProduct.AutoSize = true;
            this.labProduct.Location = new System.Drawing.Point(22, 84);
            this.labProduct.Name = "labProduct";
            this.labProduct.Size = new System.Drawing.Size(37, 15);
            this.labProduct.TabIndex = 0;
            this.labProduct.Text = "产品";
            // 
            // labShoppingCar
            // 
            this.labShoppingCar.AutoSize = true;
            this.labShoppingCar.Location = new System.Drawing.Point(22, 286);
            this.labShoppingCar.Name = "labShoppingCar";
            this.labShoppingCar.Size = new System.Drawing.Size(52, 15);
            this.labShoppingCar.TabIndex = 2;
            this.labShoppingCar.Text = "购物车";
            // 
            // dgvShoppingCar
            // 
            this.dgvShoppingCar.AutoGenerateColumns = false;
            this.dgvShoppingCar.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvShoppingCar.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.shoppingCartItemIDDataGridViewTextBoxColumn,
            this.shoppingCartIDDataGridViewTextBoxColumn,
            this.quantityDataGridViewTextBoxColumn1,
            this.productIDDataGridViewTextBoxColumn1,
            this.dateCreatedDataGridViewTextBoxColumn,
            this.modifiedDateDataGridViewTextBoxColumn});
            this.dgvShoppingCar.DataMember = "ShoppingCartItem";
            this.dgvShoppingCar.DataSource = this.dataSet21;
            this.dgvShoppingCar.Location = new System.Drawing.Point(25, 304);
            this.dgvShoppingCar.Name = "dgvShoppingCar";
            this.dgvShoppingCar.RowTemplate.Height = 27;
            this.dgvShoppingCar.Size = new System.Drawing.Size(421, 150);
            this.dgvShoppingCar.TabIndex = 3;
            // 
            // btnAdd
            // 
            this.btnAdd.AutoSize = true;
            this.btnAdd.Location = new System.Drawing.Point(499, 182);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(75, 25);
            this.btnAdd.TabIndex = 4;
            this.btnAdd.Text = "添加";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // btnRemove
            // 
            this.btnRemove.AutoSize = true;
            this.btnRemove.Location = new System.Drawing.Point(499, 384);
            this.btnRemove.Name = "btnRemove";
            this.btnRemove.Size = new System.Drawing.Size(75, 25);
            this.btnRemove.TabIndex = 5;
            this.btnRemove.Text = "删除";
            this.btnRemove.UseVisualStyleBackColor = true;
            this.btnRemove.Click += new System.EventHandler(this.btnRemove_Click);
            // 
            // oleDbSelectCommand1
            // 
            this.oleDbSelectCommand1.CommandText = resources.GetString("oleDbSelectCommand1.CommandText");
            this.oleDbSelectCommand1.Connection = this.oleDbConnection1;
            // 
            // oleDbUpdateCommand1
            // 
            this.oleDbUpdateCommand1.CommandText = resources.GetString("oleDbUpdateCommand1.CommandText");
            this.oleDbUpdateCommand1.Connection = this.oleDbConnection1;
            this.oleDbUpdateCommand1.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("Name", System.Data.OleDb.OleDbType.VarWChar, 0, "Name"),
            new System.Data.OleDb.OleDbParameter("Color", System.Data.OleDb.OleDbType.VarWChar, 0, "Color"),
            new System.Data.OleDb.OleDbParameter("ListPrice", System.Data.OleDb.OleDbType.Currency, 0, "ListPrice"),
            new System.Data.OleDb.OleDbParameter("Weight", System.Data.OleDb.OleDbType.Numeric, 0, System.Data.ParameterDirection.Input, false, ((byte)(8)), ((byte)(2)), "Weight", System.Data.DataRowVersion.Current, null),
            new System.Data.OleDb.OleDbParameter("Original_ProductID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ProductID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_Name", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "Name", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_Color", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "Color", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_Color", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "Color", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_ListPrice", System.Data.OleDb.OleDbType.Currency, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ListPrice", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_Weight", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "Weight", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_Weight", System.Data.OleDb.OleDbType.Numeric, 0, System.Data.ParameterDirection.Input, false, ((byte)(8)), ((byte)(2)), "Weight", System.Data.DataRowVersion.Original, null)});
            // 
            // oleDbDeleteCommand1
            // 
            this.oleDbDeleteCommand1.CommandText = resources.GetString("oleDbDeleteCommand1.CommandText");
            this.oleDbDeleteCommand1.Connection = this.oleDbConnection1;
            this.oleDbDeleteCommand1.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("Original_ProductID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ProductID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_Name", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "Name", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_Color", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "Color", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_Color", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "Color", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_ListPrice", System.Data.OleDb.OleDbType.Currency, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ListPrice", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_Weight", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "Weight", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_Weight", System.Data.OleDb.OleDbType.Numeric, 0, System.Data.ParameterDirection.Input, false, ((byte)(8)), ((byte)(2)), "Weight", System.Data.DataRowVersion.Original, null)});
            // 
            // oleDbDataAdapter1
            // 
            this.oleDbDataAdapter1.DeleteCommand = this.oleDbDeleteCommand1;
            this.oleDbDataAdapter1.SelectCommand = this.oleDbSelectCommand1;
            this.oleDbDataAdapter1.TableMappings.AddRange(new System.Data.Common.DataTableMapping[] {
            new System.Data.Common.DataTableMapping("Table", "Product", new System.Data.Common.DataColumnMapping[] {
                        new System.Data.Common.DataColumnMapping("ProductID", "ProductID"),
                        new System.Data.Common.DataColumnMapping("Name", "Name"),
                        new System.Data.Common.DataColumnMapping("Color", "Color"),
                        new System.Data.Common.DataColumnMapping("ListPrice", "ListPrice"),
                        new System.Data.Common.DataColumnMapping("Weight", "Weight"),
                        new System.Data.Common.DataColumnMapping("Quantity", "Quantity")})});
            this.oleDbDataAdapter1.UpdateCommand = this.oleDbUpdateCommand1;
            // 
            // oleDbConnection1
            // 
            this.oleDbConnection1.ConnectionString = "Provider=SQLNCLI11;Data Source=localhost;Integrated Security=SSPI;Initial Catalog" +
    "=AdventureWorks";
            // 
            // oleDbSelectCommand2
            // 
            this.oleDbSelectCommand2.CommandText = "SELECT  ShoppingCartItemID, ShoppingCartID, Quantity, ProductID, DateCreated, Mod" +
    "ifiedDate\r\nFROM      Sales.ShoppingCartItem";
            this.oleDbSelectCommand2.Connection = this.oleDbConnection1;
            // 
            // oleDbInsertCommand1
            // 
            this.oleDbInsertCommand1.CommandText = "INSERT INTO [AdventureWorks].[Sales].[ShoppingCartItem] ([ShoppingCartID], [Quant" +
    "ity], [ProductID], [DateCreated], [ModifiedDate]) VALUES (?, ?, ?, ?, ?)";
            this.oleDbInsertCommand1.Connection = this.oleDbConnection1;
            this.oleDbInsertCommand1.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("ShoppingCartID", System.Data.OleDb.OleDbType.VarWChar, 0, "ShoppingCartID"),
            new System.Data.OleDb.OleDbParameter("Quantity", System.Data.OleDb.OleDbType.Integer, 0, "Quantity"),
            new System.Data.OleDb.OleDbParameter("ProductID", System.Data.OleDb.OleDbType.Integer, 0, "ProductID"),
            new System.Data.OleDb.OleDbParameter("DateCreated", System.Data.OleDb.OleDbType.DBTimeStamp, 0, "DateCreated"),
            new System.Data.OleDb.OleDbParameter("ModifiedDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, "ModifiedDate")});
            // 
            // oleDbUpdateCommand2
            // 
            this.oleDbUpdateCommand2.CommandText = resources.GetString("oleDbUpdateCommand2.CommandText");
            this.oleDbUpdateCommand2.Connection = this.oleDbConnection1;
            this.oleDbUpdateCommand2.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("ShoppingCartID", System.Data.OleDb.OleDbType.VarWChar, 0, "ShoppingCartID"),
            new System.Data.OleDb.OleDbParameter("Quantity", System.Data.OleDb.OleDbType.Integer, 0, "Quantity"),
            new System.Data.OleDb.OleDbParameter("ProductID", System.Data.OleDb.OleDbType.Integer, 0, "ProductID"),
            new System.Data.OleDb.OleDbParameter("DateCreated", System.Data.OleDb.OleDbType.DBTimeStamp, 0, "DateCreated"),
            new System.Data.OleDb.OleDbParameter("ModifiedDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, "ModifiedDate"),
            new System.Data.OleDb.OleDbParameter("Original_ShoppingCartItemID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ShoppingCartItemID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_ShoppingCartID", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ShoppingCartID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_Quantity", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "Quantity", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_ProductID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ProductID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_DateCreated", System.Data.OleDb.OleDbType.DBTimeStamp, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "DateCreated", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_ModifiedDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ModifiedDate", System.Data.DataRowVersion.Original, null)});
            // 
            // oleDbDeleteCommand2
            // 
            this.oleDbDeleteCommand2.CommandText = resources.GetString("oleDbDeleteCommand2.CommandText");
            this.oleDbDeleteCommand2.Connection = this.oleDbConnection1;
            this.oleDbDeleteCommand2.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("Original_ShoppingCartItemID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ShoppingCartItemID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_ShoppingCartID", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ShoppingCartID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_Quantity", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "Quantity", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_ProductID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ProductID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_DateCreated", System.Data.OleDb.OleDbType.DBTimeStamp, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "DateCreated", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_ModifiedDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ModifiedDate", System.Data.DataRowVersion.Original, null)});
            // 
            // oleDbDataAdapter2
            // 
            this.oleDbDataAdapter2.DeleteCommand = this.oleDbDeleteCommand2;
            this.oleDbDataAdapter2.InsertCommand = this.oleDbInsertCommand1;
            this.oleDbDataAdapter2.SelectCommand = this.oleDbSelectCommand2;
            this.oleDbDataAdapter2.TableMappings.AddRange(new System.Data.Common.DataTableMapping[] {
            new System.Data.Common.DataTableMapping("Table", "ShoppingCartItem", new System.Data.Common.DataColumnMapping[] {
                        new System.Data.Common.DataColumnMapping("ShoppingCartItemID", "ShoppingCartItemID"),
                        new System.Data.Common.DataColumnMapping("ShoppingCartID", "ShoppingCartID"),
                        new System.Data.Common.DataColumnMapping("Quantity", "Quantity"),
                        new System.Data.Common.DataColumnMapping("ProductID", "ProductID"),
                        new System.Data.Common.DataColumnMapping("DateCreated", "DateCreated"),
                        new System.Data.Common.DataColumnMapping("ModifiedDate", "ModifiedDate")})});
            this.oleDbDataAdapter2.UpdateCommand = this.oleDbUpdateCommand2;
            // 
            // dataSet21
            // 
            this.dataSet21.DataSetName = "DataSet2";
            this.dataSet21.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // shoppingCartItemIDDataGridViewTextBoxColumn
            // 
            this.shoppingCartItemIDDataGridViewTextBoxColumn.DataPropertyName = "ShoppingCartItemID";
            this.shoppingCartItemIDDataGridViewTextBoxColumn.HeaderText = "ShoppingCartItemID";
            this.shoppingCartItemIDDataGridViewTextBoxColumn.Name = "shoppingCartItemIDDataGridViewTextBoxColumn";
            this.shoppingCartItemIDDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // shoppingCartIDDataGridViewTextBoxColumn
            // 
            this.shoppingCartIDDataGridViewTextBoxColumn.DataPropertyName = "ShoppingCartID";
            this.shoppingCartIDDataGridViewTextBoxColumn.HeaderText = "ShoppingCartID";
            this.shoppingCartIDDataGridViewTextBoxColumn.Name = "shoppingCartIDDataGridViewTextBoxColumn";
            // 
            // quantityDataGridViewTextBoxColumn1
            // 
            this.quantityDataGridViewTextBoxColumn1.DataPropertyName = "Quantity";
            this.quantityDataGridViewTextBoxColumn1.HeaderText = "Quantity";
            this.quantityDataGridViewTextBoxColumn1.Name = "quantityDataGridViewTextBoxColumn1";
            // 
            // productIDDataGridViewTextBoxColumn1
            // 
            this.productIDDataGridViewTextBoxColumn1.DataPropertyName = "ProductID";
            this.productIDDataGridViewTextBoxColumn1.HeaderText = "ProductID";
            this.productIDDataGridViewTextBoxColumn1.Name = "productIDDataGridViewTextBoxColumn1";
            // 
            // dateCreatedDataGridViewTextBoxColumn
            // 
            this.dateCreatedDataGridViewTextBoxColumn.DataPropertyName = "DateCreated";
            this.dateCreatedDataGridViewTextBoxColumn.HeaderText = "DateCreated";
            this.dateCreatedDataGridViewTextBoxColumn.Name = "dateCreatedDataGridViewTextBoxColumn";
            // 
            // modifiedDateDataGridViewTextBoxColumn
            // 
            this.modifiedDateDataGridViewTextBoxColumn.DataPropertyName = "ModifiedDate";
            this.modifiedDateDataGridViewTextBoxColumn.HeaderText = "ModifiedDate";
            this.modifiedDateDataGridViewTextBoxColumn.Name = "modifiedDateDataGridViewTextBoxColumn";
            // 
            // labUserID
            // 
            this.labUserID.AutoSize = true;
            this.labUserID.Location = new System.Drawing.Point(143, 36);
            this.labUserID.Name = "labUserID";
            this.labUserID.Size = new System.Drawing.Size(67, 15);
            this.labUserID.TabIndex = 6;
            this.labUserID.Text = "用户编号";
            // 
            // tbxUserID
            // 
            this.tbxUserID.Location = new System.Drawing.Point(216, 33);
            this.tbxUserID.Name = "tbxUserID";
            this.tbxUserID.Size = new System.Drawing.Size(100, 25);
            this.tbxUserID.TabIndex = 7;
            // 
            // btnLogIn
            // 
            this.btnLogIn.AutoSize = true;
            this.btnLogIn.Location = new System.Drawing.Point(358, 32);
            this.btnLogIn.Name = "btnLogIn";
            this.btnLogIn.Size = new System.Drawing.Size(75, 25);
            this.btnLogIn.TabIndex = 8;
            this.btnLogIn.Text = "登陆";
            this.btnLogIn.UseVisualStyleBackColor = true;
            this.btnLogIn.Click += new System.EventHandler(this.btnLogIn_Click);
            // 
            // dgvProduct
            // 
            this.dgvProduct.AutoGenerateColumns = false;
            this.dgvProduct.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvProduct.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.productIDDataGridViewTextBoxColumn,
            this.nameDataGridViewTextBoxColumn,
            this.colorDataGridViewTextBoxColumn,
            this.listPriceDataGridViewTextBoxColumn,
            this.weightDataGridViewTextBoxColumn,
            this.quantityDataGridViewTextBoxColumn});
            this.dgvProduct.DataMember = "Product";
            this.dgvProduct.DataSource = this.dataSet11;
            this.dgvProduct.Location = new System.Drawing.Point(25, 117);
            this.dgvProduct.Name = "dgvProduct";
            this.dgvProduct.RowTemplate.Height = 27;
            this.dgvProduct.Size = new System.Drawing.Size(421, 150);
            this.dgvProduct.TabIndex = 1;
            // 
            // productIDDataGridViewTextBoxColumn
            // 
            this.productIDDataGridViewTextBoxColumn.DataPropertyName = "ProductID";
            this.productIDDataGridViewTextBoxColumn.HeaderText = "ProductID";
            this.productIDDataGridViewTextBoxColumn.Name = "productIDDataGridViewTextBoxColumn";
            this.productIDDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // nameDataGridViewTextBoxColumn
            // 
            this.nameDataGridViewTextBoxColumn.DataPropertyName = "Name";
            this.nameDataGridViewTextBoxColumn.HeaderText = "Name";
            this.nameDataGridViewTextBoxColumn.Name = "nameDataGridViewTextBoxColumn";
            // 
            // colorDataGridViewTextBoxColumn
            // 
            this.colorDataGridViewTextBoxColumn.DataPropertyName = "Color";
            this.colorDataGridViewTextBoxColumn.HeaderText = "Color";
            this.colorDataGridViewTextBoxColumn.Name = "colorDataGridViewTextBoxColumn";
            // 
            // listPriceDataGridViewTextBoxColumn
            // 
            this.listPriceDataGridViewTextBoxColumn.DataPropertyName = "ListPrice";
            this.listPriceDataGridViewTextBoxColumn.HeaderText = "ListPrice";
            this.listPriceDataGridViewTextBoxColumn.Name = "listPriceDataGridViewTextBoxColumn";
            // 
            // weightDataGridViewTextBoxColumn
            // 
            this.weightDataGridViewTextBoxColumn.DataPropertyName = "Weight";
            this.weightDataGridViewTextBoxColumn.HeaderText = "Weight";
            this.weightDataGridViewTextBoxColumn.Name = "weightDataGridViewTextBoxColumn";
            // 
            // quantityDataGridViewTextBoxColumn
            // 
            this.quantityDataGridViewTextBoxColumn.DataPropertyName = "Quantity";
            this.quantityDataGridViewTextBoxColumn.HeaderText = "Quantity";
            this.quantityDataGridViewTextBoxColumn.Name = "quantityDataGridViewTextBoxColumn";
            this.quantityDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // dataSet11
            // 
            this.dataSet11.DataSetName = "DataSet1";
            this.dataSet11.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(648, 466);
            this.Controls.Add(this.btnLogIn);
            this.Controls.Add(this.tbxUserID);
            this.Controls.Add(this.labUserID);
            this.Controls.Add(this.btnRemove);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.dgvShoppingCar);
            this.Controls.Add(this.labShoppingCar);
            this.Controls.Add(this.dgvProduct);
            this.Controls.Add(this.labProduct);
            this.Name = "Form1";
            this.Text = "ShoppingCar";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dgvShoppingCar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet21)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgvProduct)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet11)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labProduct;
        private System.Windows.Forms.DataGridView dgvProduct;
        private System.Windows.Forms.Label labShoppingCar;
        private System.Windows.Forms.DataGridView dgvShoppingCar;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button btnRemove;
        private System.Windows.Forms.DataGridViewTextBoxColumn productIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn nameDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn colorDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn listPriceDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn weightDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn quantityDataGridViewTextBoxColumn;
        private DataSet1 dataSet11;
        private System.Data.OleDb.OleDbCommand oleDbSelectCommand1;
        private System.Data.OleDb.OleDbConnection oleDbConnection1;
        private System.Data.OleDb.OleDbCommand oleDbUpdateCommand1;
        private System.Data.OleDb.OleDbCommand oleDbDeleteCommand1;
        private System.Data.OleDb.OleDbDataAdapter oleDbDataAdapter1;
        private System.Data.OleDb.OleDbCommand oleDbSelectCommand2;
        private System.Data.OleDb.OleDbCommand oleDbInsertCommand1;
        private System.Data.OleDb.OleDbCommand oleDbUpdateCommand2;
        private System.Data.OleDb.OleDbCommand oleDbDeleteCommand2;
        private System.Data.OleDb.OleDbDataAdapter oleDbDataAdapter2;
        private System.Windows.Forms.DataGridViewTextBoxColumn shoppingCartItemIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn shoppingCartIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn quantityDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn productIDDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn dateCreatedDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn modifiedDateDataGridViewTextBoxColumn;
        private DataSet2 dataSet21;
        private System.Windows.Forms.Label labUserID;
        private System.Windows.Forms.TextBox tbxUserID;
        private System.Windows.Forms.Button btnLogIn;
    }
}

