#pragma once //include�� �������Ȱ�� 1���� ����ϵ�����.

class Spiker
{
	bool m_bPower;
	float m_fVolume;
public:
	Spiker()
	{
		m_bPower = false;
		m_fVolume = 0;
	}
	void SwitchOn()
	{
		m_bPower = true;
	}
	void SwitchOff()
	{
		m_bPower = false;
	}
	void VolumeUp()
	{
		m_fVolume++;
	}
	void VolumeDown()
	{
		m_fVolume--;
	}
};

class Antena
{
	float m_fHertz;
public:
	void HertzUp()
	{
		m_fHertz++;
	}
	void HertzDown()
	{
		m_fHertz--;
	}
};
//is-a: ����� �̿��ϸ� �ڵ带 ���� �ۼ������ʰ� ������ִ�.
class RadioIsA : public Spiker, public Antena
{

};
//has-a: �� ��ü�� ���δ� �Լ��� ������Ѵ�.(����)
//���鶧 ������ ��ǰ�� �� ���� ��ǰ�� ����Ҽ��ִ�.
//(���ǿ� ������� ���� �������̽��� ���ο� ���忡 �����ϹǷ� ���⿡ �ش�ɼ��� �ִ�.)
class RadioHasA
{
	Spiker* m_pSpiker;
	Antena* m_pAntena;
public:
	RadioHasA(Spiker* spiker, Antena* antena)
	{
		m_pSpiker = spiker;
		m_pAntena = antena;
	}
	void SwitchOn()
	{
		m_pSpiker->SwitchOn();
	}
	void SwitchOff()
	{
		m_pSpiker->SwitchOff();
	}
	void VolumeUp()
	{
		m_pSpiker->VolumeUp();
	}
	void VolumeDown()
	{
		m_pSpiker->VolumeDown();
	}
	void HertzUp()
	{
		m_pAntena->HertzUp();
	}
	void HertzDown()
	{
		m_pAntena->HertzDown();
	}
};

void RadioMain()
{
	RadioIsA cRadioIsA; //������ ������ִ�. �׷��� ���κ�ǰ�� ��Ȱ���Ҽ�����.

	Spiker* pSpiker = new Spiker();
	Antena* pAntena = new Antena();

	//������ �����Ҷ� ��ǰ�� �����Ҽ��ְ�, ��Ȱ���� �����ϴ�.
	RadioHasA cRadio(pSpiker,pAntena);
	cRadio.SwitchOn();
	cRadio.VolumeUp();
	cRadio.HertzDown();
	cRadio.SwitchOff();

	delete pSpiker;
	delete pAntena;
}