#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "struct.h"
using namespace std;

entity entity_choosing(string entity_name);
bool batte_player(entity player, entity enemy);
weapon weapon_choosing(string weapon_name);

bool story1(entity player)
{
	// -----���¿�ʼ------
	cout << "���¡���" << endl;
	Sleep(1000);
	cin.get();
	cout << "(ʹ�ûس��������飩" << endl;
	cin.get();
	cout << "�۹���1328�꣬������ڶ���������˹����һ���߾���ׯ�����մ塣" << endl;
	cin.get();
	cout << "���ĸ���ó��ֹ���֯�������ϵ����ﶼ����һ��һ�߷��ƶ��ɡ�" << endl;
	cin.get();
	cout << "����ĸ��ף���һ�������ϱ���ƾ������ս����ĥ������ս�����ɣ�ʱ��ʱ�ܴӸ�����ɽ���Ե���ͷҰ�ޡ�" << endl;
	cin.get();
	cout << "�����Ǽ�ʶ��ս���Ĳпᣬ��ĸ��״�С�ͽ̵��㽣����" << endl;
	cin.get();
	cout << "�����ڴˣ���һֱ�Ǵ�����ǿ׳��С������17�����꣬���һ�������еĽ��������ִ�ׯ����������ս����" << endl;
	cin.get();
	cout << "���㲢����һ�������Ѫ���ˣ��ӿ�ʱ���Ǳܿ�Ҫ����Ҳ��׷�����ܵĵ��ˡ�" << endl;
	cin.get();
	cout << "�ڻ�����������֮�����ͷ�����ף��������Ľ���û��һ��Ѫ��" << endl;
	cin.get();
	cout << "��Ȼս��ʱ�з����������ǵ���������ƽ�ͼ��ӡ�" << endl;
	cin.get();
	cout << "ֱ����������£��㷢�ָ��׵ľ���״̬��Щ���ȶ���" << endl;
	cin.get();
	cout << "����������һ���ּ�С���ϣ�̧ͷ������ȴ�����������̫������������������ա�ʱ�������ˮһ��ճ�����ҵ�ÿһ���������������Բ�ε����ݣ��ҿ���������ѹ��Խ��ԽС��ɢ������ϸ�����ĭ����" << endl;
	cin.get();
	cout << "����־��������ʱ�����������鷿������д����ʲô��" << endl;
	cin.get();
	cout << "����Ϊ����ѹ��̫���µģ����������Ľ���Խ��ԽƵ�������׵Ľ��Ͽ�ʼմȾѪ������Ȼ��֪����˭��Ѫ��" << endl;
	cin.get();
	cout << "������һ�����ϣ�����ĵ��»��Ƿ����ˡ�" << endl;
	cin.get();
	cout << "����ʧ���ˡ�" << endl;
	cin.get();
	cout << "���ƿ�����ס���鷿�ţ�ȴ��㱻���ص��������" << endl;
	cin.get();
	cout << "ԭ����������������ϵ������ɢ��һ�أ�����򿪵����϶������ʲݵ��ּ���" << endl;
	cin.get();
	cout << "��һ�߼��ѵ��������Ѱ����ŵ㣬һ����������е����ݡ�" << endl;
	cin.get();
	cout << "�м�����������ɻ�ɬ�Ѷ����ķ�д�ͣ��ƺ��������һ�����ص���ʽ�������֪ʶ�жϣ������ڶ�ħѧ���о����롣" << endl;
	cin.get();
	cout << "�㲻֪��һ��ϰ��ĸ���Ϊ�λ�������о���Щ����������Ȼ�����е����ġ�" << endl;
	cin.get();
	cout << "�ű�һ�������������������ע�⣬��ʹ�ּ�ʮ���ʲ����⣬���㻹���ϳ�������Ǹ��׵��ֱʡ�" << endl;
	cin.get();
	cout << "���Ǹ��׵��ռǣ����һ����¼�����죺" << endl;
	cin.get();
	cout << "���������Ѿ��ӽ������࡭�����ּ�⡭ֻҪɱ���������ҵ�����˵ʲô���ҵ������Ѿ��ߵ��˾�ͷ�����һ���δ��֮�£���ʱ������ⳡ��Խ��ʮ��ĸ����ˡ���" << endl;
	cin.get();
	cout << "������𺳣�û�뵽һ���ºͿ���ĸ��׾�������˳��صĹ�����" << endl;
	cin.get();
	cout << "���𡭽����ϵ���Ѫ��" << endl;
	cin.get();
	cout << "�����¿�ȥ��������һ���ֻ�ĵ�ͼ��������еĵص���ȶԣ�����ʶ������ǼҸ����ĵ�ͼ��" << endl;
	cin.get();
	cout << "�ҵ�λ�ñ����һ������ǣ�����Զ����ɽ��������һ��Ѫ��ɫ�Ĳ档" << endl;
	cin.get();
	cout << "�����뵣���������в������͡�" << endl;
	cin.get();
	cout << "�Ը�������ľ���״̬�����óȻս��������������롣" << endl;
	cin.get();
	cout << "���������룬�㳭���ռ����뻳�У�Ťͷ��Ҫ������š�" << endl;
	cin.get();
	cout << "�Լ�˼������ص��Լ��ķ��䣬�����������Լ���������" << endl;
	cin.get();
	cout << weapon_choosing(player.weapon).description << endl;
	cin.get();
	cout << "Ϊ�˸����������������Ľ������Ѿ������˼���Сȱ�ڡ�" << endl;
	cin.get();
	cout << "���׵Ľ���һ��ʮ�����������ɡ�" << endl;
	cin.get();
	cout << "һ�뵽���ף���������ٴ��Թ�һ�󽹼���" << endl;
	cin.get();
	cout << "����Ҫ�ҵ����ף���������������" << endl;
	cin.get();
	cout << "ĸ�׶����ͻȻ������Щ���ȣ�������Ĭ���ˣ����׵�ʧ�ٶ����Ĵ���ܴ�" << endl;
	cin.get();
	cout << "�뿪�Һ��㾶ֱ����ɽ����ȥ��" << endl;
	cin.get();
	cout << "ɽ�е�·����������ֻ��û�����׵Ļ�ѩ������������Ľ��ȡ�" << endl;
	cin.get();
	cout << "���ļ���ٵس���ɽ���н���ȫȻû��ע�⵽·�߲ݴԵ��춯��" << endl;
	cin.get();
	cout << "��Ұ��Ե����һ����Ӱ���������ת������ס�˽�����" << endl;
	cin.get();
	cout << "һƥҰ�������ĵض����㣬��һ��������ͦ����ѩ���У�ȫ�����Ǻ�������������֫΢΢�������ƺ����ڻ���������ֻ�дӷ�������������˿˿��������֤�����Ǹ����" << endl;
	cin.get();
	cout << "������һ�������γ���������" << endl;
	cin.get();

	bool battle_ans = batte_player(player, entity_choosing("Ұ��"));
	if (battle_ans == false)
	{
		Sleep(1000);
		cout << "\nս��ʧ�ܡ���" << endl;
		return false;
	}
	cout << "\n\n\n(ʹ�ûس��������飩" << endl;
	cin.get();
	cout << "һ��ս����Ұ���Ѿ���ǿ��֮ĩ������Ȼ����������������" << endl;
	cin.get();
	cout << "��ѹ�����壬������ӳ�����һ��Ļ��ȣ����������ʺ���" << endl;
	cin.get();
	cout << "��Ѫ����Ȫ��������Ⱦ����һ��Ƭ���档" << endl;
	cin.get();
	cout << "Ұ�ǵ������ڿ��л���һ���������������ߣ�������ص�����ѩ���ϡ�" << endl;
	cin.get();
	cout << "���ư�ɫ�����������Ŀ��к��˿ڴ��������𣬷·����������ꡣ" << endl;
	cin.get();
	cout << "�����նɱ�����ĸо���" << endl;
	cin.get();
	cout << "ʤ��������ϲ�ú͵���˲��������ɢ����ĺ�����ô��أ��ò����������𽣡�" << endl;
	cin.get();
	cout << "Ϊ�����棬�������ܱ��������ǿ���������" << endl;
	cin.get();
	cout << "��ץ��Ұ�ǵ�ʬ�壬׼������Ų��·�ߵĿ�ľ�ԡ�" << endl;
	cin.get();
	cout << "��ѩ��ɽ���գ�һ���˸����������Ž�ɽ��" << endl;
	cin.get();
	cout << "˵�������Ǹ��ס�" << endl;
	cin.get();
	cout << "��������Ұ�ǵ�ʬ�壬��˳�Ž�ӡ����ǰ����" << endl;
	cin.get();
	cout << "1003�������" << endl;
	cin.get();
	return true;
}