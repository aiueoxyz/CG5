#pragma once
#include <string>         // wstring, string
#include <d3d12.h>        // ID3DBlob
#include <d3dcompiler.h>  // dxcapi.h が依存している
#include <dxcapi.h>       // IDxcBlobを利用するため


// Shaderクラス
class Shader {
public:
	// シェーダーファイルを読み込み、コンパイル済みデータを生成する
	void Load(const std::wstring& filePath, const std::wstring& shaderModel);
	void LoadDxc(const std::wstring& filePath, const std::wstring& shaderModel);

	// 生成したコンパイル済みデータを取得する
	ID3DBlob* GetBlob();
	IDxcBlob* GetDxcBlob();

	// コンストラクタ
	Shader();
	// デストラクタ
	~Shader();

private:
	// コンパイル済みのシェーダーデータ
	// コンストラクタで初期化しなくていい
	// データメンバの定義(*.h)内で初期化できる ※C++11以降
	ID3DBlob* blob_ = nullptr;
	
	// コンパイル済みのシェーダーデータ ※外部コンパイル版
	IDxcBlob* dxcBlob_ = nullptr;
};
