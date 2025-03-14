// CFILEWIN.cpp: 实现文件
//

#include "pch.h"
#include "MFC_DIP_BMPViewer.h"
#include "afxdialogex.h"
#include "CFILEWIN.h"


// CFILEWIN 对话框

IMPLEMENT_DYNAMIC(CFILEWIN, CDialogEx)

CFILEWIN::CFILEWIN(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FILEWIN, pParent)
{

}

CFILEWIN::~CFILEWIN()
{
}

void CFILEWIN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCSHELLTREE1, m_shellTree);
	DDX_Control(pDX, IDC_MFCSHELLLIST1, m_shellList);
}


BEGIN_MESSAGE_MAP(CFILEWIN, CDialogEx)
	ON_NOTIFY(TVN_SELCHANGED, IDC_MFCSHELLTREE1, &CFILEWIN::OnTvnSelchangedMfcshelltree1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_MFCSHELLLIST1, &CFILEWIN::OnLvnItemchangedMfcshelllist1)
END_MESSAGE_MAP()


// CFILEWIN 消息处理程序

void CFILEWIN::OnTvnSelchangedMfcshelltree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	//获取路径
	CString str_path;
	m_shellTree.GetItemPath(str_path,pNMTreeView->itemNew.hItem);
	
	m_shellList.DisplayFolder(str_path);//显示文件夹

	*pResult = 0;
}

//点击shelllist组件的时候
void CFILEWIN::OnLvnItemchangedMfcshelllist1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	//CString file_path;
	//for (int i = 0; i < m_shellList.GetItemCount(); i++)
	//{
 //       if (m_shellList.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
	//	{
	//		m_shellList.GetItemPath(file_path,i);
	//		MessageBox(file_path);
	//		//MessageBox("已选择文件："+ file_path +"，请退出窗口后");

	//		break;
	//	}
	//}

	*pResult = 0;
}
