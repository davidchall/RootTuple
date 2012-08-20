#include "RootTuple.h"

//------------------------------------------------------------------------------------
// 
//                                  Public methods
// 
//------------------------------------------------------------------------------------
RootTuple::RootTuple() :
m_filename("output.root"), m_treename("tree")
{
}//Constructor

RootTuple::RootTuple(std::string filename, std::string treename) :
m_filename(filename), m_treename(treename)
{
	if(treename.empty()){
		std::cout << "RootTuple:: Warning: Using default tree name" << std::endl;
		m_treename = "tree";
	}
	std::string fileExtension = ".root";
	if(filename.length() <= fileExtension.length()){
		std::cout << "RootTuple:: Warning: Using default file name" << std::endl;
		m_filename = "output.root";
	}
	if(filename.compare(filename.length() - fileExtension.length(), fileExtension.length(), fileExtension) != 0){
		m_filename = filename + ".root";
	}
}//Constructor

RootTuple::~RootTuple()
{
}//Destructor

void RootTuple::Initialise()
{
	// Create TFile object
	m_file = new TFile(m_filename.c_str(), "RECREATE");
	if(!m_file){
		std::cout << "RootTuple:: Error: Cannot create ROOT file" << std::endl;
		return;
	}

	// Create TTree object
	m_tree = new TTree(m_treename.c_str(), m_treename.c_str());
	if(!m_tree){
		std::cout << "RootTuple:: Error: Cannot create ROOT tree" << std::endl;
	}

	DeclareBranches();
}//Initialise

void RootTuple::SetCompressionLevel(int i)
{
	if(m_file && i >= 0 && i <= 9)
		m_file->SetCompressionLevel(i);
}//SetCompressionLevel

void RootTuple::AddEvent()
{
	// Check vectors sizes consistent
	if ((int)m_Px.size() != m_barcode.size() ||
		(int)m_Py.size() != m_barcode.size() ||
		(int)m_Pz.size() != m_barcode.size() ||
		(int)m_E.size()  != m_barcode.size())
		std::cout << "RootTuple:: Warning: Inconsistent vector sizes" << std::endl;

	FillBranches();
	ClearVectors();
}//AddEvent

void RootTuple::Write()
{
	if(m_file)
		m_file->Write();
	else
		std::cout << "RootTuple:: Error: No ROOT file was opened" << std::endl;
}//Write

void RootTuple::Close()
{
	if(m_file){
		m_file->Write();
		m_file->Close();
		delete m_file;
	}
	else
		std::cout << "RootTuple:: Error: No ROOT file was opened" << std::endl;
}//Close

void RootTuple::AddParticle(int barcode, double px, double py, double pz, double e)
{
	m_barcode.push_back(barcode);
	m_Px.push_back(px);
	m_Py.push_back(py);
	m_Pz.push_back(pz);
	m_E.push_back(e);
}//AddParticle

void RootTuple::SetWeight(double weight)
{
	m_weight = weight;
}//SetWeight

void RootTuple::SetIteration(int iteration)
{
	m_iteration = iteration;
}//SetIteration

//------------------------------------------------------------------------------------
// 
//                                  Public methods
// 
//------------------------------------------------------------------------------------
void RootTuple::DeclareBranches()
{
	m_tree->Branch("weight",    &m_weight);
	m_tree->Branch("iteration", &m_iteration);

	m_tree->Branch("barcode",   &m_barcode);
	m_tree->Branch("Px",        &m_Px);
	m_tree->Branch("Py",        &m_Py);
	m_tree->Branch("Pz",        &m_Pz);
	m_tree->Branch("E",         &m_E);
}//DeclareBranches

void RootTuple::FillBranches()
{
	if(m_tree)
		m_tree->Fill();
}//FillBranches

void RootTuple::ClearVectors()
{
	m_barcode.clear();
	m_Px.clear();
	m_Py.clear();
	m_Pz.clear();
	m_E.clear();
}//ClearVectors
