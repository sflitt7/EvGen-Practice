#include <TMath.h>
#include <TRandom.h>
void asym(){
	TFile *evgen1 = new TFile("~/EvGen/out/5cm/compton_p_200_in1.root");
	TH1F *phi = (TH1F*)evgen1->Get("h6");

	Double_t y_par = phi->Integral(phi->FindBin(-5),phi->FindBin(5));
	Double_t y_per = phi->Integral(phi->FindBin(85),phi->FindBin(95));

	Double_t asy = (y_par-y_per)/(y_par+y_per);

	cout<<asy<<endl;

	TF1* as = new TF1("as", "[0]*(1+[1]*cos((2*x+[2])*TMath::DegToRad()))",-180,180);
	phi->Fit("as");
	Double_t a = as->GetParameter(1);
	cout<<a<<endl;
//here p gamma is 1 so there is no need to divide

//below is evgen again with 90 phi offset
	TFile *evgen2 = new TFile("~/EvGen/out/5cm/compton_p_200_in.root");
	TH1F *phi90 = (TH1F*)evgen2->Get("h6");

	TH1F* hAdd = new TH1F("hAdd","",720,-180,180);
	hAdd->Add(phi,phi90,1,1);
	TH1F* hSub = new TH1F("hSub","",720,-180,180);
	hSub->Add(phi,phi90,1,-1);

	auto dividend=new TH1F(*hSub);
	dividend->Divide(hAdd);

	TF1* asym = new TF1("asym","([0]*cos(2*x*TMath::DegToRad()))",-180,180);
	dividend->Fit("asym");
	Double_t a2 = asym->GetParameter(0);
	cout<<a2<<endl;
}
