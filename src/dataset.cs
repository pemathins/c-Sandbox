using System.Data;
namespace WinformDataSet
{
    public partial class Form1 : Form
    {
        public DataSet ds;
        public DataTable dt;
        public DataTable course;
        public DataRow row; 
        public Form1()
        { 
            InitializeComponent();
            createForm();
        }
        
        private void createForm()
        {
            ds = new DataSet();
            dt = new DataTable(); 
            dt = createTableStudent();
            ds.Tables.Add(dt);
            course = createTableCourse();
            ds.Tables.Add(course);
            addValuesCourse();
            comboBox1.DataSource = course;
            
            comboBox1.DisplayMember = "courseName";
            comboBox1.ValueMember = "courseId";
        }

        private DataTable createTableStudent()
        {
            DataTable dts = new DataTable();
            DataColumn regno = new DataColumn("Regno", typeof(int));
            DataColumn name = new DataColumn("Name", typeof(string));
    
            dts.Columns.Add(regno);
            dts.PrimaryKey = new DataColumn[] { regno };
            dts.Columns.Add(name);
            dts.Columns.Add(new DataColumn("courseId", typeof(int)));
            return dts;
        }
        private DataTable createTableCourse()
        {
            course = new DataTable();
            DataColumn courseId = new DataColumn("courseId", typeof(int));
            course.Columns.Add(courseId);
            course.Columns.Add(new DataColumn("courseName", typeof(string)));
            course.PrimaryKey = new DataColumn[] { course.Columns[0] };
            return course;
        }
        private int AddValueStudents(string regno, string name)
        {
            
            row = dt.NewRow();
            row["Regno"] = regno;
            row["Name"] = name;
            row["courseId"] = comboBox1.SelectedValue;
            dt.Rows.Add(row);
            return 0;
        }
        private void addValuesCourse()
        {
            DataRow row1;
            row1 = course.NewRow();
            row1["courseId"] = 1;
            row1["courseName"] = "Mca";
            course.Rows.Add(row1);

            row = course.NewRow();
            row["courseId"] =2;
            row["courseName"] = "Bca";
            course.Rows.Add(row);
        }
        private void button1_Click(object sender, EventArgs e)
        {
            dataGridView1.DataSource = dt;
            if (AddValueStudents(textBox1.Text, textBox2.Text) == 0)
            {
                MessageBox.Show("value saved in DataTable!");
            }

        }
    }
}