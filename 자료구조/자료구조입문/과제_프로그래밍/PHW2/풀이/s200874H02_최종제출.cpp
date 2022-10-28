
#include "H02_polyAdd.h"
extern int allocSize;	   // size of the allocated memory for each test
extern int allocSizeMax;  // max allocated mem size among those of all tests

void readPolyAB(int* pnA, polyPtr* pA, int* pnB, polyPtr* pB) {

	// pnA, pnB : ���׽� A�� B�� nonzero term�� ������ �����ϴ�
	//            nA, nB�� ����Ű�� pointers
	// pA : ���׽� A�� �����ϴ� �迭�� ����Ű�� pointer A�� ����Ű�� pointer
	//      ��, poly pointer�� pointer�̴�.
	// pB : ���׽� B�� �����ϴ� �迭�� ����Ű�� pointer B�� ����Ű�� pointer
	// ����: �� �Լ����� �迭�� �迭�� ũ�Ⱑ �����ǹǷ� �̿� ���� pointer��
	//      parameter�� �Է¹޴´�.
	//
	// ��� : �Է¿��� ���׽� A�� B�� ���� �ڷḦ �о� �����Ѵ�.
	//        HW pdf�� �Է� ���� ������ ��������
	// ���� :  
	//  -- �� ���׽��� zero polynomial �� �� �ִ�.
	//     �Է� �ڷᰡ ������ ��� WRONG INPUT ��ũ�θ� �����Ѵ�.
	//  -- A, B ������ ���� �޸𸮴� MALLOC ��ũ�θ� ���� �ѹ����� ����Ͽ�
	//     �Ҵ�޾ƾ� �Ѵ�.

	*pnA = *pnB = 0;

	// ���׽� A, ���׽� B�� �Է��� ���� ���� �ްڽ��ϴ�.

	// 1. ���׽� A�� ���õ� Data�� �Է� �޽��ϴ�.

	// (1) scanf �Լ��� ���׽� A�� ���� ������ �Է� �޽��ϴ�: ������ pnA�� �̿��Ͽ� nA�� ���� �����մϴ�.

	if (scanf("%d", pnA) == EOF)
	{
		WRONG_INPUT;    // �Է� �ڷᰡ ������ ���, WRONG INPUT ��ũ�� ����
	}

	// (2) ���׽� A�� ������ �޸𸮸� ���� �Ҵ� �մϴ�.

	if (*pnA < 0)       // ���� ������ ������ ���
	{
		WRONG_INPUT;    // �������, WRONG INPUT ��ũ�� ����
	}
	else if (*pnA > 0)  // ���� ������ ����� ���
	{
		MALLOC(*pA, polyPtr, sizeof(poly) * (*pnA)); // MALLOC ��ũ�η� A ������ ���� �޸𸮸� �Ҵ�
		for (int i = 0; i < (*pnA); i++)    // A�� ���� ������ŭ for�� �ݺ�: �Է� �ڷ� ���� ���θ� üũ�ϱ� ���� ����
		{
			if (scanf("%d %d", &((*pA)[i].coef), &((*pA)[i].expon)) == EOF)
			{
				WRONG_INPUT;    // �Է� �ڷᰡ ������ ���, WRONG INPUT ��ũ�� ����
			}
		}
	}

	/*
	���� ������ 0�� ���(zero polynomial)�� ���� ���ǹ��� ������ �ʾ�,
	MALLOC ��ũ�ΰ� ������� �ʵ��� �߽��ϴ�.
	�̴� �Ʒ��� ���׽� B�� ���õ� Data�� �Է� ���� ������ ���������Դϴ�.
	*/


	// 2. ���׽� B�� ���õ� Data�� �Է� �ްڽ��ϴ�.

	// (1) scanf �Լ��� ���׽� B�� ���� ������ �Է� �޽��ϴ�: ������ pnB�� �̿��Ͽ� nB�� ���� �����մϴ�

	if (scanf("%d", pnB) == EOF)
	{
		WRONG_INPUT;    // �Է� �ڷᰡ ������ ���, WRONG INPUT ��ũ�� ����
	}

	// (2) ���׽� B�� ������ �޸𸮸� ���� �Ҵ� �մϴ�.

	if (*pnB < 0)       // ���� ������ ������ ���
	{
		WRONG_INPUT;    // �������, WRONG INPUT ��ũ�� ����
	}
	else if (*pnB > 0)  // ���� ������ ����� ���
	{
		MALLOC(*pB, polyPtr, sizeof(poly) * (*pnB)); // MALLOC ��ũ�η� A ������ ���� �޸𸮸� �Ҵ�
		for (int i = 0; i < (*pnB); i++)    // A�� ���� ������ŭ for�� �ݺ�: �Է� �ڷ� ���� ���θ� üũ�ϱ� ���� ����
		{
			if (scanf("%d %d", &((*pB)[i].coef), &((*pB)[i].expon)) == EOF)
			{
				WRONG_INPUT;    // �Է� �ڷᰡ ������ ���, WRONG INPUT ��ũ�� ����
			}
		}
	}

	return;
}

int allocPolyD(int nA, polyPtr A, int nB, polyPtr B, polyPtr* pD) {

	// nA, nB : ���׽� A�� B�� term �� (0�� ���� �ִ�)
	//
	// ��� : A+B�� �����ϱ� ���Ͽ� �ʿ��� �޸� ũ�⸦ ���Ͽ� �� ũ�� ��ŭ��
	//       �޸𸮸� �Ҵ�޴´�.
	//       �� �ʿ��� ��ŭ�� �Ҵ�޾ƾ� �Ѵ�. �׷���, ���� A+B�� zero
	//       polynimial�̶�� �޸𸮸� �Ҵ���� �ʴ´�.
	// 
	// ���
	//   pD : A+B�� �����ϱ� ���Ͽ� �Ҵ��� �޸𸮸� ����Ű�� pointer��
	//        pointer.
	//   nD : A+B�� term �� (�̴� return�Ѵ�)
	//        ���� A+B�� zero polynomial�̶�� nD = 0�� return�Ѵ�(�� ���,
	//        *pD = NULL�� ����(���ʿ��ϴϱ�).
	//
	// ����
	// -- A+B ������ ���Ͽ� �ʿ��� �޸𸮴� MALLOC ��ũ�θ� �� �� ���� ����Ͽ� 
	//    allocation�Ͽ��� �Ѵ�(�̸� ���� ������ ����)
	//    ��, �ʿ��� �޸� ũ�⸦ ��Ȯ�� ���Ͽ� MALLOC ��ũ�θ� �����Ѵ�.
	// -- ���������� allocsize�� dynamic allocation�� �޸� ũ�⸦ �����ؾ� �Ѵ�.

	int nD = 0; *pD = NULL;

	int coef_temp;      // ���׽��� ���� simulation �������� ���׽� A�� B�� ������ ���� ���,
						// �ӽ������� ����� ���� ��Ƴ��� ���� ���� coef_temp�� ����

	int sA = 0, sB = 0;     // ���׽� A, B���� ���ؾ� �ϴ� ���� �ľ��ϱ� ���� startA�� startB ���� ����

	// 1. ���׽��� ���� ������ simulation �Ͽ�, A+B�� �����ϱ� ���Ͽ� �ʿ��� �޸� ũ��(nD)�� ���մϴ�.
	// �ʿ��� �޸� ũ��� ���� ���� nD�� �����Ͽ� return�� ���� ����� �����Դϴ�.
	// �̶� �߿��� ��, ���׽� A�� B�� ���� ������ 0��(zero polynomial)���� Ȯ���ؾ� �Ѵٴ� ���Դϴ�.

	// (1) ���׽� A�� zero polynomial, ���׽� B�� zero polynomial�� �ƴ� ���
	// ���׽� D�� ���� ���� nD�� ���׽� B�� ���� ���� nB�� ���Դϴ�.

	if (nA == 0 && nB != 0)
	{
		nD = nB;
	}

	// (2) ���׽� B�� zero polynomial, ���׽� A�� zero polynomial�� �ƴ� ���
	// ���׽� D�� ���� ���� nD�� ���׽� A�� ���� ���� nA�� ���Դϴ�.

	else if (nA != 0 && nB == 0)
	{
		nD = nA;
	}

	// (3) ���׽� A, B ��� zero polynomial�� �ƴ� ���

	else if (nA != 0 && nB != 0)
	{
		// ���׽� A, B �� �� ���׽��� ���� ������ ��� ������ ������ ���� simulation�� �ݺ��մϴ�.

		while (sA < nA && sB < nB)
		{
			switch (COMPARE(A[sA].expon, B[sB].expon)) {
			case -1:									// case: a�� ���� < b�� ����
				nD++;									// ������ �ٸ��ٸ� �������� ����� �͵� ���� nD�� �ϳ� �� �ʿ�
				sB++;									// startB ���� +1 �Ͽ� ���� ������ �̵�
				break;

			case 0:										// case: a�� ���� = b�� ����
				coef_temp = A[sA].coef + B[sB].coef;	// coef_temp�� a�� ��� + b�� ����� ���� �����Ͽ� �Է�
				if (coef_temp)							// ���׽� A, B�� ����� ���� 0�� �ƴ� ����� ����
				{
					nD++;								// nD ���� +1 �Ͽ� ���� �߰��� �޸� ũ�� ����
				} 
				sA++;									// startA ���� +1 �Ͽ� ���� ������ �̵�
				sB++;									// startB ���� +1 �Ͽ� ���� ������ �̵�
				break;

			case 1:										// case: a�� ���� > b�� ����
				nD++;									// ������ �ٸ��ٸ� �������� ����� �͵� ���� nD�� �ϳ� �� �ʿ�
				sA++;									// startA ���� +1 �Ͽ� ���� ������ �̵�
				break;
			}
		}

		// ���� ������ ���� ����, ���׽��� ó���մϴ�.
		// �Ʒ� �� for�� �� ���ǿ� �´� �� for���� ����� ���Դϴ�.

		for (; sA < nA; sA++) {
			nD++;
			sA++;
		}
			

		for (; sB < nB; sB++) {
			nD++;
			sB++;
		}
			
	}

	// (4) ���׽� A, B�� ��� zero polynomial�� ���
	// �� if�� �� � �͵� ������� �����Ƿ�, ó���� �ʱ�ȭ�� ��� nD = 0, *pD = NULL�� ���Դϴ�.


	// 2. nD�� ���� ���� MALLOC ��ũ�θ� �����Ͽ�, �޸� ũ�⸦ �Ҵ��մϴ�.

	if (nD != 0)    // nD�� �ƴ� ��쿡��, �޸� ũ�⸦ �Ҵ��մϴ�.
	{
		MALLOC(*pD, polyPtr, sizeof(poly) * (nD));
	}


	// 3. ���������� allocSize�� dynamic allocation�� �޸� ũ�⸦ �����մϴ�.

	allocSize = nA * sizeof(poly) + nB * sizeof(poly) + nD * sizeof(poly);

	return nD;
}

void addPoly(int nA, polyPtr A, int nB, polyPtr B, int nD, polyPtr D) {

	// �Է�
	// nA, nB : ���׽� A�� B�� term ����
	// A, B   : ���׽� �迭 (�̵��� zero polynomial�� ���� �ִ�)
	// 
	// ���
	// nD, D  : A+B�� term �� �� ��� (zero polynomial�� ���� �ִ�)
	// ����: nD�� �迭 D�� ���� storage�� �̸� �����Ǿ� �Էµȴ�.


	int coef_temp;					// ���׽��� ���� �������� ���׽� A�� B�� ������ ���� ���,
									// �ӽ������� ����� ���� ��Ƴ��� ���� ���� coef_temp�� ����
	int sA = 0, sB = 0, sD = 0;     // ������ �� ���� �ľ��ϱ� ���� startA, startB, startD ���� ����

	// 1. ���׽� A, B, D�� zero polynomial ���ο� ���� case�� �з��ϰ�,
	// ���� ������ �� ������ �ܼ� ���縦 �� ������ �����մϴ�.

	// (1) ���׽� A�� zero polynomial, ���׽� B�� zero polynomial�� �ƴ� ���
	// ���׽� D�� ���� ������ �� �ʿ� ����, ���׽� B�� ���� ���Դϴ�.

	if (nA == 0 && nB != 0)
	{
		for (int i = 0; i < nB; i++)
		{
			D[i] = B[i];
		}
	}

	// (2) ���׽� B�� zero polynomial, ���׽� A�� zero polynomial�� �ƴ� ���
	// ���׽� D�� ���� ������ �� �ʿ� ����, ���׽� A�� ���� ���Դϴ�.

	else if (nA != 0 && nB == 0)
	{
		for (int i = 0; i < nA; i++)
		{
			D[i] = A[i];
		}
	}

	// (3) ���׽� A, B ��� zero polynomial�� �ƴ� ���

	else if (nA != 0 && nB != 0)
	{
		// ���׽� A, B �� �� ���׽��� ���� ������ ��� ������ ������ ���� ������ �ݺ��մϴ�.

		while (sA < nA && sB < nB)
		{
			switch (COMPARE(A[sA].expon, B[sB].expon)) {
			case -1:									// case: a�� ���� < b�� ����
				D[sD].coef = B[sB].coef;
				D[sD].expon = B[sB].expon;
				sB++;									// startB ���� +1 �Ͽ� ���� ������ �̵�
				sD++;									// startD ���� +1 �Ͽ� ���� ������ �̵�
				break;

			case 0:     // case: a�� ���� = b�� ����
				coef_temp = A[sA].coef + B[sB].coef;	// coef_temp�� a�� ��� + b�� ����� ���� �����Ͽ� �Է�
				if (coef_temp) {						// ���׽� A, B�� ����� ���� 0�� �ƴ� ����� ����
					D[sD].coef = coef_temp;
					D[sD].expon = A[sA].expon;
					sD++;								// startD ���� +1 �Ͽ� ���� ������ �̵�
				}
				sA++;									// startA ���� +1 �Ͽ� ���� ������ �̵�
				sB++;									// startB ���� +1 �Ͽ� ���� ������ �̵�
				break;
					
			case 1:										// case: a�� ���� > b�� ����
				D[sD].coef = A[sA].coef;
				D[sD].expon = A[sA].expon;
				sA++;									// startA ���� +1 �Ͽ� ���� ������ �̵�
				sD++;									// startD ���� +1 �Ͽ� ���� ������ �̵�
				break;
			}
		}

		// ���� ������ ���� ����, ���׽��� ó���մϴ�.
		// �Ʒ� �� for�� �� ���ǿ� �´� �� for���� ����� ���Դϴ�.

		for (; sA < nA; sA++)
		{
			D[sD].coef = A[sA].coef;
			D[sD].expon = A[sA].expon;
			sA++;
			sD++;
		}
			
		for (; sB < nB; sB++)
		{
			D[sD].coef = B[sB].coef;
			D[sD].expon = B[sB].expon;
			sB++;
			sD++;
		}
			
	}

	// (4) ���׽� A, B�� ��� zero polynomial�� ���
	// �� if�� �� � �͵� ������� �����Ƿ�, ó���� �μ� ���� ���� ��� nD = 0, *pD = NULL�� ���Դϴ�.

	return;
}



