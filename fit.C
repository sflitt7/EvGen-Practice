void fit(){

	TCanvas* c1 = new TCanvas("c1","title",0,0,4000,3000);
	c1->Divide(2,2);
	c1->cd(1);

	TFile *evgen = new TFile("~/EvGen/out/5cm/pi0_p_200_in.root");
	TH1F *phi = (TH1F*)evgen->Get("h6");
	phi->GetXaxis()->SetTitle("");
	phi->GetYaxis()->SetTitle("");
	
	

	TF1* f1 = new TF1("f1","(1+[0]*cos(2*(x*TMath::DegToRad()+[1])))*[2]",-180,180);
	f1->SetParLimits(0,0,5);
	f1->SetParLimits(1,-1,1);
	f1->SetParLimits(2,0,160);

	f1->SetLineColor(8);
	phi->Fit(f1);
	phi->Draw();

	c1->cd(2);

	TF1* l = new TF1("l","",-180,180);
	l->SetLineColor(8);

	l->FixParameter(0,f1->GetParameter(0));
	l->FixParameter(1,f1->GetParameter(1));
	l->FixParameter(2,f1->GetParameter(2));

	gStyle->SetOptFit(1);
	f1->Draw();

}
