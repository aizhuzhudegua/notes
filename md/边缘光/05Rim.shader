// Upgrade NOTE: replaced '_Object2World' with 'unity_ObjectToWorld'

// Upgrade NOTE: replaced '_World2Object' with 'unity_WorldToObject'

Shader "CS0105/05Rim"
{
    Properties
    {
        _MainTex ("Texture", 2D) = "white" {}
    
        _MainColor("MainColor",Color) = (1,1,1,1)
        _Cutout("Cutout",Range(-0.1,1.1)) = 0.0
        _Speed("Speed",Vector) = (1,1,0,0)
        _Emiss("Emiss",Float) = 1.0
        _RimPower("RimPower",Float) = 1.0
            
    }
    SubShader
    {
        // ‰÷»æ∂”¡–
        Tags{"Queue" = "Transparent"}
        Pass
        {
            Cull Off
            ZWrite On
            ColorMask 0
            CGPROGRAM
            float4 _Color;
            #pragma vertex vert
            #pragma fragment frag

            float4 vert(float4 vertexPos : POSITION) :SV_POSITION
            {
                return UnityObjectToClipPos(vertexPos);
            }

            float4 frag(void) : COLOR
            {
                return _Color;
            }
            ENDCG
        }
        Pass
        {
            ZWrite Off
            Blend SrcAlpha OneMinusSrcAlpha
            // Blend SrcAlpha One
            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag


            #include "UnityCG.cginc"

            struct appdata
            {
                float4 vertex : POSITION;
                float2 uv : TEXCOORD0;
                float3 normal : NORMAL;
            };

            struct v2f
            {
                float4 vertex : SV_POSITION;
                float2 uv : TEXCOORD0;
                float3 normal_world : TEXCOORD1;
                float3 view_world : TEXCOORD2;
            };

            sampler2D _MainTex;
            float4 _MainTex_ST;
            
            float _Cutout;
            float4 _MainColor;

            float _Emiss;
            float _RimPower;

            v2f vert (appdata v)
            {
                v2f o;
                o.vertex = UnityObjectToClipPos(v.vertex);
                o.uv = v.uv * _MainTex_ST.xy + _MainTex_ST.zw;
                o.normal_world = normalize(mul(float4(v.normal, 0), unity_WorldToObject).xyz);
                
                float3 pos_world = mul(unity_ObjectToWorld, v.vertex);
                o.view_world = normalize(_WorldSpaceCameraPos.xyz - pos_world);
                return o;
            }

            half4 frag(v2f i) : SV_Target
            {
                // sample the texture
                float3 nomal_world = normalize(i.normal_world);
                float3 view_world = normalize(i.view_world);

                float NdotV = saturate(dot(nomal_world, view_world));
                float3 col = _MainColor.xyz * _Emiss;
                
                float fresnel = pow((1.0 - NdotV) ,_RimPower);
                float alpha = saturate(fresnel * _Emiss);

                return float4(col,alpha);
            }
            ENDCG
        }
    }
}
