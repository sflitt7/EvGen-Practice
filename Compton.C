void Plot(){
	TFile *evgen = new TFile("~/EvGen/out/5cm/compton_p_300_in.root");
	TH1F *theta = (TH1F*)evgen->Get("h4");
	theta->GetXaxis()->SetTitle("x axis");
	theta->GetYaxis()->SetTitle("y axis");
	theta->SetFillColor(38);
	theta->Draw();

}
