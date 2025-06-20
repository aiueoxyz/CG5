#pragma once
#include <d3d12.h>   // ID3D12Resource, D3D12_VERTEX_BUFFER_VIEW

class VertexBuffer {
public:
	// VertexBuffer生成
	void Create(const UINT size, const UINT stride);

	// ゲッター
	ID3D12Resource* Get();                // 頂点バッファー
	D3D12_VERTEX_BUFFER_VIEW* GetView();  // 頂点バッファービュー

	// コンストラクタ
	VertexBuffer();
	// デストラクタ
	~VertexBuffer();

private:
	ID3D12Resource* vertexBuffer_ = nullptr;       // 頂点バッファ
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView_{};  // 頂点バッファビュー
};