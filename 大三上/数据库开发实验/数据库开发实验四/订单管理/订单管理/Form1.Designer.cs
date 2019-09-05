namespace 订单管理
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
            this.labOrder = new System.Windows.Forms.Label();
            this.labOrderDetail = new System.Windows.Forms.Label();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.btnSelect = new System.Windows.Forms.Button();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.oleDbSelectCommand1 = new System.Data.OleDb.OleDbCommand();
            this.oleDbConnection1 = new System.Data.OleDb.OleDbConnection();
            this.oleDbUpdateCommand1 = new System.Data.OleDb.OleDbCommand();
            this.oleDbDeleteCommand1 = new System.Data.OleDb.OleDbCommand();
            this.oleDbDataAdapter1 = new System.Data.OleDb.OleDbDataAdapter();
            this.oleDbSelectCommand2 = new System.Data.OleDb.OleDbCommand();
            this.oleDbInsertCommand1 = new System.Data.OleDb.OleDbCommand();
            this.oleDbUpdateCommand2 = new System.Data.OleDb.OleDbCommand();
            this.oleDbDeleteCommand2 = new System.Data.OleDb.OleDbCommand();
            this.oleDbDataAdapter2 = new System.Data.OleDb.OleDbDataAdapter();
            this.dgvOrderDetail = new System.Windows.Forms.DataGridView();
            this.salesOrderIDDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.salesOrderDetailIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.carrierTrackingNumberDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.orderQtyDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.productIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.specialOfferIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.unitPriceDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.unitPriceDiscountDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.lineTotalDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.rowguidDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.modifiedDateDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataSet11 = new 订单管理.DataSet1();
            this.dgvOrder = new System.Windows.Forms.DataGridView();
            this.salesOrderIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.orderDateDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dueDateDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.shipDateDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.statusDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.salesOrderNumberDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataSet21 = new 订单管理.DataSet2();
            ((System.ComponentModel.ISupportInitialize)(this.dgvOrderDetail)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet11)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgvOrder)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet21)).BeginInit();
            this.SuspendLayout();
            // 
            // labOrder
            // 
            this.labOrder.AutoSize = true;
            this.labOrder.Location = new System.Drawing.Point(41, 32);
            this.labOrder.Name = "labOrder";
            this.labOrder.Size = new System.Drawing.Size(37, 15);
            this.labOrder.TabIndex = 0;
            this.labOrder.Text = "订单";
            // 
            // labOrderDetail
            // 
            this.labOrderDetail.AutoSize = true;
            this.labOrderDetail.Location = new System.Drawing.Point(41, 222);
            this.labOrderDetail.Name = "labOrderDetail";
            this.labOrderDetail.Size = new System.Drawing.Size(67, 15);
            this.labOrderDetail.TabIndex = 2;
            this.labOrderDetail.Text = "订单明细";
            this.labOrderDetail.Click += new System.EventHandler(this.label2_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.AutoSize = true;
            this.btnDelete.Location = new System.Drawing.Point(222, 419);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(63, 25);
            this.btnDelete.TabIndex = 4;
            this.btnDelete.Text = "删除";
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // btnSave
            // 
            this.btnSave.AutoSize = true;
            this.btnSave.Location = new System.Drawing.Point(356, 419);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(66, 25);
            this.btnSave.TabIndex = 5;
            this.btnSave.Text = "保存";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // btnClose
            // 
            this.btnClose.AutoSize = true;
            this.btnClose.Location = new System.Drawing.Point(486, 419);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(67, 25);
            this.btnClose.TabIndex = 6;
            this.btnClose.Text = "关闭";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // btnSelect
            // 
            this.btnSelect.AutoSize = true;
            this.btnSelect.Location = new System.Drawing.Point(580, 68);
            this.btnSelect.Name = "btnSelect";
            this.btnSelect.Size = new System.Drawing.Size(78, 25);
            this.btnSelect.TabIndex = 7;
            this.btnSelect.Text = "查询";
            this.btnSelect.UseVisualStyleBackColor = true;
            this.btnSelect.Click += new System.EventHandler(this.btnSelect_Click);
            // 
            // btnUpdate
            // 
            this.btnUpdate.AutoSize = true;
            this.btnUpdate.Location = new System.Drawing.Point(580, 316);
            this.btnUpdate.Name = "btnUpdate";
            this.btnUpdate.Size = new System.Drawing.Size(78, 25);
            this.btnUpdate.TabIndex = 8;
            this.btnUpdate.Text = "更新";
            this.btnUpdate.UseVisualStyleBackColor = true;
            this.btnUpdate.Click += new System.EventHandler(this.btnUpdate_Click);
            // 
            // oleDbSelectCommand1
            // 
            this.oleDbSelectCommand1.CommandText = "SELECT  SalesOrderID, OrderDate, DueDate, ShipDate, Status, SalesOrderNumber\r\nFRO" +
    "M      Sales.SalesOrderHeader";
            this.oleDbSelectCommand1.Connection = this.oleDbConnection1;
            // 
            // oleDbConnection1
            // 
            this.oleDbConnection1.ConnectionString = "Provider=SQLNCLI11;Data Source=localhost;Integrated Security=SSPI;Initial Catalog" +
    "=AdventureWorks";
            // 
            // oleDbUpdateCommand1
            // 
            this.oleDbUpdateCommand1.CommandText = resources.GetString("oleDbUpdateCommand1.CommandText");
            this.oleDbUpdateCommand1.Connection = this.oleDbConnection1;
            this.oleDbUpdateCommand1.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("OrderDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, "OrderDate"),
            new System.Data.OleDb.OleDbParameter("DueDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, "DueDate"),
            new System.Data.OleDb.OleDbParameter("ShipDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, "ShipDate"),
            new System.Data.OleDb.OleDbParameter("Status", System.Data.OleDb.OleDbType.UnsignedTinyInt, 0, "Status"),
            new System.Data.OleDb.OleDbParameter("Original_SalesOrderID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "SalesOrderID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_OrderDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "OrderDate", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_DueDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "DueDate", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_ShipDate", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "ShipDate", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_ShipDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ShipDate", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_Status", System.Data.OleDb.OleDbType.UnsignedTinyInt, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "Status", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_SalesOrderNumber", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "SalesOrderNumber", System.Data.DataRowVersion.Original, null)});
            // 
            // oleDbDeleteCommand1
            // 
            this.oleDbDeleteCommand1.CommandText = resources.GetString("oleDbDeleteCommand1.CommandText");
            this.oleDbDeleteCommand1.Connection = this.oleDbConnection1;
            this.oleDbDeleteCommand1.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("Original_SalesOrderID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "SalesOrderID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_OrderDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "OrderDate", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_DueDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "DueDate", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_ShipDate", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "ShipDate", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_ShipDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ShipDate", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_Status", System.Data.OleDb.OleDbType.UnsignedTinyInt, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "Status", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_SalesOrderNumber", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "SalesOrderNumber", System.Data.DataRowVersion.Original, null)});
            // 
            // oleDbDataAdapter1
            // 
            this.oleDbDataAdapter1.DeleteCommand = this.oleDbDeleteCommand1;
            this.oleDbDataAdapter1.SelectCommand = this.oleDbSelectCommand1;
            this.oleDbDataAdapter1.TableMappings.AddRange(new System.Data.Common.DataTableMapping[] {
            new System.Data.Common.DataTableMapping("Table", "SalesOrderHeader", new System.Data.Common.DataColumnMapping[] {
                        new System.Data.Common.DataColumnMapping("SalesOrderID", "SalesOrderID"),
                        new System.Data.Common.DataColumnMapping("OrderDate", "OrderDate"),
                        new System.Data.Common.DataColumnMapping("DueDate", "DueDate"),
                        new System.Data.Common.DataColumnMapping("ShipDate", "ShipDate"),
                        new System.Data.Common.DataColumnMapping("Status", "Status"),
                        new System.Data.Common.DataColumnMapping("SalesOrderNumber", "SalesOrderNumber")})});
            this.oleDbDataAdapter1.UpdateCommand = this.oleDbUpdateCommand1;
            // 
            // oleDbSelectCommand2
            // 
            this.oleDbSelectCommand2.CommandText = resources.GetString("oleDbSelectCommand2.CommandText");
            this.oleDbSelectCommand2.Connection = this.oleDbConnection1;
            // 
            // oleDbInsertCommand1
            // 
            this.oleDbInsertCommand1.CommandText = resources.GetString("oleDbInsertCommand1.CommandText");
            this.oleDbInsertCommand1.Connection = this.oleDbConnection1;
            this.oleDbInsertCommand1.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("SalesOrderID", System.Data.OleDb.OleDbType.Integer, 0, "SalesOrderID"),
            new System.Data.OleDb.OleDbParameter("CarrierTrackingNumber", System.Data.OleDb.OleDbType.VarWChar, 0, "CarrierTrackingNumber"),
            new System.Data.OleDb.OleDbParameter("OrderQty", System.Data.OleDb.OleDbType.SmallInt, 0, "OrderQty"),
            new System.Data.OleDb.OleDbParameter("ProductID", System.Data.OleDb.OleDbType.Integer, 0, "ProductID"),
            new System.Data.OleDb.OleDbParameter("SpecialOfferID", System.Data.OleDb.OleDbType.Integer, 0, "SpecialOfferID"),
            new System.Data.OleDb.OleDbParameter("UnitPrice", System.Data.OleDb.OleDbType.Currency, 0, "UnitPrice"),
            new System.Data.OleDb.OleDbParameter("UnitPriceDiscount", System.Data.OleDb.OleDbType.Currency, 0, "UnitPriceDiscount"),
            new System.Data.OleDb.OleDbParameter("rowguid", System.Data.OleDb.OleDbType.Guid, 0, "rowguid"),
            new System.Data.OleDb.OleDbParameter("ModifiedDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, "ModifiedDate")});
            // 
            // oleDbUpdateCommand2
            // 
            this.oleDbUpdateCommand2.CommandText = resources.GetString("oleDbUpdateCommand2.CommandText");
            this.oleDbUpdateCommand2.Connection = this.oleDbConnection1;
            this.oleDbUpdateCommand2.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("SalesOrderID", System.Data.OleDb.OleDbType.Integer, 0, "SalesOrderID"),
            new System.Data.OleDb.OleDbParameter("CarrierTrackingNumber", System.Data.OleDb.OleDbType.VarWChar, 0, "CarrierTrackingNumber"),
            new System.Data.OleDb.OleDbParameter("OrderQty", System.Data.OleDb.OleDbType.SmallInt, 0, "OrderQty"),
            new System.Data.OleDb.OleDbParameter("ProductID", System.Data.OleDb.OleDbType.Integer, 0, "ProductID"),
            new System.Data.OleDb.OleDbParameter("SpecialOfferID", System.Data.OleDb.OleDbType.Integer, 0, "SpecialOfferID"),
            new System.Data.OleDb.OleDbParameter("UnitPrice", System.Data.OleDb.OleDbType.Currency, 0, "UnitPrice"),
            new System.Data.OleDb.OleDbParameter("UnitPriceDiscount", System.Data.OleDb.OleDbType.Currency, 0, "UnitPriceDiscount"),
            new System.Data.OleDb.OleDbParameter("rowguid", System.Data.OleDb.OleDbType.Guid, 0, "rowguid"),
            new System.Data.OleDb.OleDbParameter("ModifiedDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, "ModifiedDate"),
            new System.Data.OleDb.OleDbParameter("Original_SalesOrderID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "SalesOrderID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_SalesOrderDetailID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "SalesOrderDetailID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_CarrierTrackingNumber", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "CarrierTrackingNumber", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_CarrierTrackingNumber", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "CarrierTrackingNumber", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_OrderQty", System.Data.OleDb.OleDbType.SmallInt, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "OrderQty", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_ProductID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ProductID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_SpecialOfferID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "SpecialOfferID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_UnitPrice", System.Data.OleDb.OleDbType.Currency, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "UnitPrice", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_UnitPriceDiscount", System.Data.OleDb.OleDbType.Currency, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "UnitPriceDiscount", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_LineTotal", System.Data.OleDb.OleDbType.Numeric, 0, System.Data.ParameterDirection.Input, false, ((byte)(38)), ((byte)(6)), "LineTotal", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_rowguid", System.Data.OleDb.OleDbType.Guid, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "rowguid", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_ModifiedDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ModifiedDate", System.Data.DataRowVersion.Original, null)});
            // 
            // oleDbDeleteCommand2
            // 
            this.oleDbDeleteCommand2.CommandText = resources.GetString("oleDbDeleteCommand2.CommandText");
            this.oleDbDeleteCommand2.Connection = this.oleDbConnection1;
            this.oleDbDeleteCommand2.Parameters.AddRange(new System.Data.OleDb.OleDbParameter[] {
            new System.Data.OleDb.OleDbParameter("Original_SalesOrderID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "SalesOrderID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_SalesOrderDetailID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "SalesOrderDetailID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("IsNull_CarrierTrackingNumber", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, ((byte)(0)), ((byte)(0)), "CarrierTrackingNumber", System.Data.DataRowVersion.Original, true, null),
            new System.Data.OleDb.OleDbParameter("Original_CarrierTrackingNumber", System.Data.OleDb.OleDbType.VarWChar, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "CarrierTrackingNumber", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_OrderQty", System.Data.OleDb.OleDbType.SmallInt, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "OrderQty", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_ProductID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ProductID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_SpecialOfferID", System.Data.OleDb.OleDbType.Integer, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "SpecialOfferID", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_UnitPrice", System.Data.OleDb.OleDbType.Currency, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "UnitPrice", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_UnitPriceDiscount", System.Data.OleDb.OleDbType.Currency, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "UnitPriceDiscount", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_LineTotal", System.Data.OleDb.OleDbType.Numeric, 0, System.Data.ParameterDirection.Input, false, ((byte)(38)), ((byte)(6)), "LineTotal", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_rowguid", System.Data.OleDb.OleDbType.Guid, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "rowguid", System.Data.DataRowVersion.Original, null),
            new System.Data.OleDb.OleDbParameter("Original_ModifiedDate", System.Data.OleDb.OleDbType.DBTimeStamp, 0, System.Data.ParameterDirection.Input, false, ((byte)(0)), ((byte)(0)), "ModifiedDate", System.Data.DataRowVersion.Original, null)});
            // 
            // oleDbDataAdapter2
            // 
            this.oleDbDataAdapter2.DeleteCommand = this.oleDbDeleteCommand2;
            this.oleDbDataAdapter2.InsertCommand = this.oleDbInsertCommand1;
            this.oleDbDataAdapter2.SelectCommand = this.oleDbSelectCommand2;
            this.oleDbDataAdapter2.TableMappings.AddRange(new System.Data.Common.DataTableMapping[] {
            new System.Data.Common.DataTableMapping("Table", "SalesOrderDetail", new System.Data.Common.DataColumnMapping[] {
                        new System.Data.Common.DataColumnMapping("SalesOrderID", "SalesOrderID"),
                        new System.Data.Common.DataColumnMapping("SalesOrderDetailID", "SalesOrderDetailID"),
                        new System.Data.Common.DataColumnMapping("CarrierTrackingNumber", "CarrierTrackingNumber"),
                        new System.Data.Common.DataColumnMapping("OrderQty", "OrderQty"),
                        new System.Data.Common.DataColumnMapping("ProductID", "ProductID"),
                        new System.Data.Common.DataColumnMapping("SpecialOfferID", "SpecialOfferID"),
                        new System.Data.Common.DataColumnMapping("UnitPrice", "UnitPrice"),
                        new System.Data.Common.DataColumnMapping("UnitPriceDiscount", "UnitPriceDiscount"),
                        new System.Data.Common.DataColumnMapping("LineTotal", "LineTotal"),
                        new System.Data.Common.DataColumnMapping("rowguid", "rowguid"),
                        new System.Data.Common.DataColumnMapping("ModifiedDate", "ModifiedDate")})});
            this.oleDbDataAdapter2.UpdateCommand = this.oleDbUpdateCommand2;
            // 
            // dgvOrderDetail
            // 
            this.dgvOrderDetail.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dgvOrderDetail.AutoGenerateColumns = false;
            this.dgvOrderDetail.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvOrderDetail.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.salesOrderIDDataGridViewTextBoxColumn1,
            this.salesOrderDetailIDDataGridViewTextBoxColumn,
            this.carrierTrackingNumberDataGridViewTextBoxColumn,
            this.orderQtyDataGridViewTextBoxColumn,
            this.productIDDataGridViewTextBoxColumn,
            this.specialOfferIDDataGridViewTextBoxColumn,
            this.unitPriceDataGridViewTextBoxColumn,
            this.unitPriceDiscountDataGridViewTextBoxColumn,
            this.lineTotalDataGridViewTextBoxColumn,
            this.rowguidDataGridViewTextBoxColumn,
            this.modifiedDateDataGridViewTextBoxColumn});
            this.dgvOrderDetail.DataMember = "SalesOrderDetail";
            this.dgvOrderDetail.DataSource = this.dataSet21;
            this.dgvOrderDetail.Location = new System.Drawing.Point(44, 240);
            this.dgvOrderDetail.Name = "dgvOrderDetail";
            this.dgvOrderDetail.RowTemplate.Height = 27;
            this.dgvOrderDetail.Size = new System.Drawing.Size(509, 150);
            this.dgvOrderDetail.TabIndex = 3;
            this.dgvOrderDetail.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvOrderDetail_CellContentClick);
            // 
            // salesOrderIDDataGridViewTextBoxColumn1
            // 
            this.salesOrderIDDataGridViewTextBoxColumn1.DataPropertyName = "SalesOrderID";
            this.salesOrderIDDataGridViewTextBoxColumn1.HeaderText = "SalesOrderID";
            this.salesOrderIDDataGridViewTextBoxColumn1.Name = "salesOrderIDDataGridViewTextBoxColumn1";
            // 
            // salesOrderDetailIDDataGridViewTextBoxColumn
            // 
            this.salesOrderDetailIDDataGridViewTextBoxColumn.DataPropertyName = "SalesOrderDetailID";
            this.salesOrderDetailIDDataGridViewTextBoxColumn.HeaderText = "SalesOrderDetailID";
            this.salesOrderDetailIDDataGridViewTextBoxColumn.Name = "salesOrderDetailIDDataGridViewTextBoxColumn";
            this.salesOrderDetailIDDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // carrierTrackingNumberDataGridViewTextBoxColumn
            // 
            this.carrierTrackingNumberDataGridViewTextBoxColumn.DataPropertyName = "CarrierTrackingNumber";
            this.carrierTrackingNumberDataGridViewTextBoxColumn.HeaderText = "CarrierTrackingNumber";
            this.carrierTrackingNumberDataGridViewTextBoxColumn.Name = "carrierTrackingNumberDataGridViewTextBoxColumn";
            // 
            // orderQtyDataGridViewTextBoxColumn
            // 
            this.orderQtyDataGridViewTextBoxColumn.DataPropertyName = "OrderQty";
            this.orderQtyDataGridViewTextBoxColumn.HeaderText = "OrderQty";
            this.orderQtyDataGridViewTextBoxColumn.Name = "orderQtyDataGridViewTextBoxColumn";
            // 
            // productIDDataGridViewTextBoxColumn
            // 
            this.productIDDataGridViewTextBoxColumn.DataPropertyName = "ProductID";
            this.productIDDataGridViewTextBoxColumn.HeaderText = "ProductID";
            this.productIDDataGridViewTextBoxColumn.Name = "productIDDataGridViewTextBoxColumn";
            // 
            // specialOfferIDDataGridViewTextBoxColumn
            // 
            this.specialOfferIDDataGridViewTextBoxColumn.DataPropertyName = "SpecialOfferID";
            this.specialOfferIDDataGridViewTextBoxColumn.HeaderText = "SpecialOfferID";
            this.specialOfferIDDataGridViewTextBoxColumn.Name = "specialOfferIDDataGridViewTextBoxColumn";
            // 
            // unitPriceDataGridViewTextBoxColumn
            // 
            this.unitPriceDataGridViewTextBoxColumn.DataPropertyName = "UnitPrice";
            this.unitPriceDataGridViewTextBoxColumn.HeaderText = "UnitPrice";
            this.unitPriceDataGridViewTextBoxColumn.Name = "unitPriceDataGridViewTextBoxColumn";
            // 
            // unitPriceDiscountDataGridViewTextBoxColumn
            // 
            this.unitPriceDiscountDataGridViewTextBoxColumn.DataPropertyName = "UnitPriceDiscount";
            this.unitPriceDiscountDataGridViewTextBoxColumn.HeaderText = "UnitPriceDiscount";
            this.unitPriceDiscountDataGridViewTextBoxColumn.Name = "unitPriceDiscountDataGridViewTextBoxColumn";
            // 
            // lineTotalDataGridViewTextBoxColumn
            // 
            this.lineTotalDataGridViewTextBoxColumn.DataPropertyName = "LineTotal";
            this.lineTotalDataGridViewTextBoxColumn.HeaderText = "LineTotal";
            this.lineTotalDataGridViewTextBoxColumn.Name = "lineTotalDataGridViewTextBoxColumn";
            this.lineTotalDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // rowguidDataGridViewTextBoxColumn
            // 
            this.rowguidDataGridViewTextBoxColumn.DataPropertyName = "rowguid";
            this.rowguidDataGridViewTextBoxColumn.HeaderText = "rowguid";
            this.rowguidDataGridViewTextBoxColumn.Name = "rowguidDataGridViewTextBoxColumn";
            // 
            // modifiedDateDataGridViewTextBoxColumn
            // 
            this.modifiedDateDataGridViewTextBoxColumn.DataPropertyName = "ModifiedDate";
            this.modifiedDateDataGridViewTextBoxColumn.HeaderText = "ModifiedDate";
            this.modifiedDateDataGridViewTextBoxColumn.Name = "modifiedDateDataGridViewTextBoxColumn";
            // 
            // dataSet11
            // 
            this.dataSet11.DataSetName = "DataSet1";
            this.dataSet11.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // dgvOrder
            // 
            this.dgvOrder.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dgvOrder.AutoGenerateColumns = false;
            this.dgvOrder.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvOrder.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.salesOrderIDDataGridViewTextBoxColumn,
            this.orderDateDataGridViewTextBoxColumn,
            this.dueDateDataGridViewTextBoxColumn,
            this.shipDateDataGridViewTextBoxColumn,
            this.statusDataGridViewTextBoxColumn,
            this.salesOrderNumberDataGridViewTextBoxColumn});
            this.dgvOrder.DataMember = "SalesOrderHeader";
            this.dgvOrder.DataSource = this.dataSet11;
            this.dgvOrder.Location = new System.Drawing.Point(44, 50);
            this.dgvOrder.Name = "dgvOrder";
            this.dgvOrder.RowTemplate.Height = 27;
            this.dgvOrder.Size = new System.Drawing.Size(506, 163);
            this.dgvOrder.TabIndex = 1;
            this.dgvOrder.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvOrder_CellContentClick);
            // 
            // salesOrderIDDataGridViewTextBoxColumn
            // 
            this.salesOrderIDDataGridViewTextBoxColumn.DataPropertyName = "SalesOrderID";
            this.salesOrderIDDataGridViewTextBoxColumn.HeaderText = "SalesOrderID";
            this.salesOrderIDDataGridViewTextBoxColumn.Name = "salesOrderIDDataGridViewTextBoxColumn";
            this.salesOrderIDDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // orderDateDataGridViewTextBoxColumn
            // 
            this.orderDateDataGridViewTextBoxColumn.DataPropertyName = "OrderDate";
            this.orderDateDataGridViewTextBoxColumn.HeaderText = "OrderDate";
            this.orderDateDataGridViewTextBoxColumn.Name = "orderDateDataGridViewTextBoxColumn";
            // 
            // dueDateDataGridViewTextBoxColumn
            // 
            this.dueDateDataGridViewTextBoxColumn.DataPropertyName = "DueDate";
            this.dueDateDataGridViewTextBoxColumn.HeaderText = "DueDate";
            this.dueDateDataGridViewTextBoxColumn.Name = "dueDateDataGridViewTextBoxColumn";
            // 
            // shipDateDataGridViewTextBoxColumn
            // 
            this.shipDateDataGridViewTextBoxColumn.DataPropertyName = "ShipDate";
            this.shipDateDataGridViewTextBoxColumn.HeaderText = "ShipDate";
            this.shipDateDataGridViewTextBoxColumn.Name = "shipDateDataGridViewTextBoxColumn";
            // 
            // statusDataGridViewTextBoxColumn
            // 
            this.statusDataGridViewTextBoxColumn.DataPropertyName = "Status";
            this.statusDataGridViewTextBoxColumn.HeaderText = "Status";
            this.statusDataGridViewTextBoxColumn.Name = "statusDataGridViewTextBoxColumn";
            // 
            // salesOrderNumberDataGridViewTextBoxColumn
            // 
            this.salesOrderNumberDataGridViewTextBoxColumn.DataPropertyName = "SalesOrderNumber";
            this.salesOrderNumberDataGridViewTextBoxColumn.HeaderText = "SalesOrderNumber";
            this.salesOrderNumberDataGridViewTextBoxColumn.Name = "salesOrderNumberDataGridViewTextBoxColumn";
            this.salesOrderNumberDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // dataSet21
            // 
            this.dataSet21.DataSetName = "DataSet2";
            this.dataSet21.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(694, 467);
            this.Controls.Add(this.btnUpdate);
            this.Controls.Add(this.btnSelect);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.dgvOrderDetail);
            this.Controls.Add(this.labOrderDetail);
            this.Controls.Add(this.dgvOrder);
            this.Controls.Add(this.labOrder);
            this.Name = "Form1";
            this.Text = "订单管理";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dgvOrderDetail)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet11)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgvOrder)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet21)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labOrder;
        private System.Windows.Forms.DataGridView dgvOrder;
        private System.Windows.Forms.Label labOrderDetail;
        private System.Windows.Forms.DataGridView dgvOrderDetail;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Button btnClose;
        private System.Windows.Forms.Button btnSelect;
        private System.Windows.Forms.Button btnUpdate;
        private System.Windows.Forms.DataGridViewTextBoxColumn salesOrderIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn orderDateDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn dueDateDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn shipDateDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn statusDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn salesOrderNumberDataGridViewTextBoxColumn;
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
        private System.Windows.Forms.DataGridViewTextBoxColumn salesOrderIDDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn salesOrderDetailIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn carrierTrackingNumberDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn orderQtyDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn productIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn specialOfferIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn unitPriceDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn unitPriceDiscountDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn lineTotalDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn rowguidDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn modifiedDateDataGridViewTextBoxColumn;
        private DataSet2 dataSet21;
    }
}

